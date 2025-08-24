#include "Timetable.h"

namespace planning {

    Timetable::Timetable() 
    {
        cout << "Timetable initialisé" << endl;
    }

    Timetable::~Timetable() 
    {
        cout << "Timetable détruit" << endl;
    }
    Timetable Timetable::instance;

    Timetable& Timetable::getInstance() 
    {
        return instance;
    }

    const set<Professor>& Timetable::getProfessors() const 
    {
        return professors;
    }
    
    const set<Classroom>& Timetable::getClassrooms() const 
    {
        return classrooms;
    }

    const set<Group>& Timetable::getGroups() const 
    {
        return groups;
    }

    list<Course>& Timetable::getCourses()
    {
        return courses;
    }

    int Timetable::addClassroom(const string& name, int seatingCapacity) 
    {
        Classroom c(name, seatingCapacity);
        c.setId(Schedulable::getCurrentId());
        classrooms.insert(c);

        return c.getId();
    }

    void Timetable::displayClassrooms() const 
    {
        for (const auto& c : classrooms) 
        {
            cout << c.toString() << endl;
        }
    }

    Classroom Timetable::findClassroomByIndex(int index) const 
    {
        auto it = classrooms.begin();
        advance(it, index);
        return *it;
    }

    Classroom Timetable::findClassroomById(int id) const 
    {
        for (const auto& c : classrooms) 
        {
            if (c.getId() == id) 
            {
                return c;
            }
        }
        return Classroom();
    }

    void Timetable::deleteClassroomByIndex(int index) 
    {
        auto it = classrooms.begin();
        advance(it, index);
        classrooms.erase(it);
    }

    void Timetable::deleteClassroomById(int id) 
    {
        auto it = classrooms.begin();
        while (it != classrooms.end()) 
        {
            if (it->getId() == id) 
            {
                classrooms.erase(it);
                return;
            }
            ++it;
        }
    }

    //----------------------------------------//PROFESSOR-----------------
    int Timetable::addProfessor(const string& lastName, const string& firstName) 
    {
        Professor p(lastName, firstName);
        int newId = Schedulable::getCurrentId();
        p.setId(newId);
        professors.insert(p);

        return newId;
    }
    void Timetable::displayProfessors() const 
    {
        for (const auto& p : professors) 
        {
            cout << p.toString() << std::endl;
        }
    }
    Professor Timetable::findProfessorById(int id) const 
    {
        for (const auto& p : professors) 
        {
            if (p.getId() == id) 
            {
                return p;
            }
        }
        return Professor(); // Retourne un objet par défaut si non trouvé
    }
    Professor Timetable::findProfessorByIndex(int index) const 
    {
        auto it = professors.begin();
        std::advance(it, index);
        return *it;
    }
    void Timetable::deleteProfessorByIndex(int index) 
    {
        auto it = professors.begin();
        advance(it, index);
        professors.erase(it);
    }
    void Timetable::deleteProfessorById(int id) 
    {
        auto it = professors.begin();
        while (it != professors.end()) 
        {
            if (it->getId() == id) 
            {
                professors.erase(it);
                return;
            }
            ++it;
        }
    }

    //-------------groupe-----------------

    int Timetable::addGroup(const string& name) 
    {
        Group g(name);
        int newId = Schedulable::getCurrentId();
        g.setId(newId);
        groups.insert(g);

        return newId;
    }
    void Timetable::displayGroups() const 
    {
        for (const auto& g : groups) 
        {
            cout << g.toString() << std::endl;
        }
    }
    Group Timetable::findGroupById(int id) const 
    {
        for (const auto& g : groups) 
        {
            if (g.getId() == id) 
            {
                return g;
            }
        }
        return Group(); 
    }
    Group Timetable::findGroupByIndex(int index) const 
    {
        auto it = groups.begin();
        std::advance(it, index);
        return *it;
    }
    void Timetable::deleteGroupByIndex(int index) 
    {
        auto it = groups.begin();
        std::advance(it, index);
        groups.erase(it);
    }

    void Timetable::deleteGroupById(int id) 
    {
        auto it = groups.begin();
        while (it != groups.end()) 
        {
            if (it->getId() == id) 
            {
                groups.erase(it);
                return;
            }
            ++it;
        }
    }
    void Timetable::save(const string& nomFichier) 
    {
        // Création des noms des fichiers
        string professorsFile = nomFichier + "_professors.xml";
        string groupsFile = nomFichier + "_groups.xml";
        string classroomsFile = nomFichier + "_classrooms.xml";
        string configFile = nomFichier + "_config.dat";
        string coursesFile = nomFichier + "_courses.xml";

        // Sérialisation des professeurs
        XmlFileSerializer<Professor> professorSerializer(professorsFile, XmlFileSerializer<Professor>::WRITE, "professors");
        for (const auto& professor : professors) 
        {
            professorSerializer.write(professor);
        }

        // Sérialisation des groupes
        XmlFileSerializer<Group> groupSerializer(groupsFile, XmlFileSerializer<Group>::WRITE, "groups");
        for (const auto& group : groups) 
        {
            groupSerializer.write(group);
        }

        // Sérialisation des locaux
        XmlFileSerializer<Classroom> classroomSerializer(classroomsFile, XmlFileSerializer<Classroom>::WRITE, "classrooms");
        for (const auto& classroom : classrooms) 
        {
            classroomSerializer.write(classroom);
        }
        XmlFileSerializer<Course> courseSerializer(coursesFile, XmlFileSerializer<Course>::WRITE, "courses");
        for (const auto& course : courses) 
        {
            courseSerializer.write(course);
        }

        // Sauvegarde de currentId au format binaire
        ofstream config(configFile, ios::binary);
        if (!config) 
        {
            perror("Erreur lors de l'ouverture du fichier de configuration pour l'écriture.");
        }
        int currentIdValeur = Schedulable::getCurrentId()-1;
        config.write(reinterpret_cast<const char*>(&currentIdValeur), sizeof(currentIdValeur));

        config.close();
    }

    void Timetable::load(const string& nomFichier) 
    {
        try 
        {
            // Construction des noms de fichiers
            string professorsFile = nomFichier + "_professors.xml";
            string groupsFile = nomFichier + "_groups.xml";
            string classroomsFile = nomFichier + "_classrooms.xml";
            string configFile = nomFichier + "_config.dat";
            string coursesFile = nomFichier + "_courses.xml";
            // Vider les conteneurs existants
            professors.clear();
            groups.clear();
            classrooms.clear();

            // Lecture de currentId depuis le fichier de configuration
            ifstream configIn(configFile, ios::binary);
            if (!configIn) 
            {
                throw runtime_error("Erreur lors de l'ouverture du fichier de configuration.");
            }

            int valeur;
            configIn.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
            if (!configIn) 
            {
                throw runtime_error("Erreur lors de la lecture de currentId.");
            }
            Schedulable::setCurrentId(valeur);
            configIn.close();

            // Désérialisation des professeurs
            try 
            {
                XmlFileSerializer<Professor> professorSerializer(professorsFile, XmlFileSerializer<Professor>::READ, "professors");
                while (true) 
                {
                    Professor professor = professorSerializer.read();
                    professors.insert(professor);
                }
            } 
            catch (const XmlFileSerializerException& e) 
            {
                if (e.getCode() == XmlFileSerializerException::END_OF_FILE) 
                {
                    printf("fin du fichier\n");
                }
            }

            // Désérialisation des groupes
            try 
            {
                XmlFileSerializer<Group> groupSerializer(groupsFile, XmlFileSerializer<Group>::READ, "groups");
                while (true) 
                {
                    Group group = groupSerializer.read();
                    groups.insert(group);
                }
            } 
            catch (const XmlFileSerializerException& e) 
            {
                if (e.getCode() == XmlFileSerializerException::END_OF_FILE) 
                {
                    printf("fin du fichier\n");
                }
            }

            // Désérialisation des locaux
            try 
            {
                XmlFileSerializer<Classroom> classroomSerializer(classroomsFile, XmlFileSerializer<Classroom>::READ, "classrooms");
                while (true) 
                {
                    Classroom classroom = classroomSerializer.read();
                    classrooms.insert(classroom);
                }
            } 
            catch (const XmlFileSerializerException& e) 
            {
                if (e.getCode() == XmlFileSerializerException::END_OF_FILE) 
                {
                    printf("fin du fichier\n");
                }
            }
            
            // Désérialisation des cours
            try 
            {
                XmlFileSerializer<Course> courseSerializer(coursesFile, XmlFileSerializer<Course>::READ, "courses");
                while (true) 
                {
                    Course cours = courseSerializer.read();
                    courses.push_back(cours);
                }
            } 
            catch (const XmlFileSerializerException& e) 
            {
                if (e.getCode() == XmlFileSerializerException::END_OF_FILE) 
                {
                    printf("fin du fichier\n");
                }
            }
            cout << "Données chargées avec succès depuis " << nomFichier << endl;

        } 
        catch (const exception& e) 
        {
            perror("Erreur lors du chargement des données\n" );
        }
    }

    void Timetable::vider() 
    {
        // Vide les conteneurs
        professors.clear();
        groups.clear();
        classrooms.clear();
    }

    bool Timetable::isProfessorAvailable(int id, const Timing& timing)const
    {
        for(const auto& course : courses)
        {
            if(course.getProfessorId() == id && course.getTiming().intersect(timing))
            {
                return false;
            }
        }
        return true;
    }

    bool Timetable::isGroupAvailable(int id, const Timing& timing) const
    {
        for(const auto& course : courses)
        {
            if(course.isGroupIdPresent(id) && course.getTiming().intersect(timing))
            {
                return false;
            }
        }
        return true;
    }
    
    bool Timetable::isClassroomAvailable(int id, const Timing& timing) const 
    {
        for (const auto& course : courses) 
        {
            if (course.getClassroomId() == id && course.getTiming().intersect(timing)) 
            {
                return false;
            }
        }
        return true;
    }

    void Timetable::schedule(Course& c, const Timing& t)
    {
         if (!isProfessorAvailable(c.getProfessorId(), t))
        throw TimingException("Le professeur n'est pas disponible à ce moment-là.",1);

        if (!isClassroomAvailable(c.getClassroomId(), t))
            throw TimingException("Le local n'est pas disponible à ce moment-là.",2);

        for (int groupId : c.getGroupsIds())
        {
            if (!isGroupAvailable(groupId, t))
                throw TimingException("Un des groupes n'est pas disponible à ce moment-là.",3);
        }

        // Attribution du timing et du code
        c.setTiming(t);
        c.setCode(Event::currentCode+=1);

        // Insère le cours dans la liste (triée chronologiquement)
        courses.push_back(c);
        courses.sort(); // Utilise l'opérateur < de Course pour maintenir l'ordre
    }

    string Timetable::tuple(const Course& c) const 
    {
        stringstream ss;

        ss << c.Event::getCode() << ";";
        ss << c.getTiming().getDay() << ";";
        ss << c.getTiming().getStart().toString() << ";";
        ss << c.getTiming().getDuration().toString() << ";";

        for (const auto& room : classrooms) 
        {
            if (room.getId() == c.getClassroomId()) 
            {
                ss << room.getName()<<";";
                break;
            }
        }


        ss << c.getTitle() << ";";

        for (const auto& prof : professors) 
        {
            if (prof.getId() == c.getProfessorId()) 
            {
                ss<<prof.getLastName();
                ss<<" ";
                ss << prof.getFirstName()<<";";

                break;
            }
        }

        bool first = true;
        for (int groupId : c.getGroupsIds()) 
        {
            for (const auto& group : groups) 
            {
                if (group.getId() == groupId) 
                {
                    if (!first) 
                        ss << ", ";
                    ss << group.getName();
                    first = false;
                    break; // Une fois trouvé, passez au prochain groupId
                }
            }
        }
        return ss.str();
    }

    void Timetable::importProfessorsFromCsv(const string& filename) 
    {
        ifstream file(filename);
        if (!file.is_open()) 
        {
            perror("Erreur : Impossible d'ouvrir le fichier ");
            return;
        }

        string line;
        while (getline(file, line)) 
        {
            istringstream iss(line);
            string lastName, firstName;

            getline(iss, lastName, ';') ;
            getline(iss, firstName, ';');
            
            addProfessor(lastName, firstName);
            
        }

        file.close();
    }

    void Timetable::importGroupsFromCsv(const string& filename) 
    {
        ifstream file(filename);
        if (!file.is_open()) 
        {
            perror("Erreur : Impossible d'ouvrir le fichier ");
            return;
        }

        string line;
        while (getline(file, line)) 
        {
            istringstream iss(line);

            string groupN;

            getline(iss, groupN, ';');
            
            addGroup(groupN);
            
        }

        file.close();
    }

    void Timetable::importClassroomsFromCsv(const string& filename) 
    {
        ifstream file(filename);
        if (!file.is_open()) 
        {
            perror("Erreur : Impossible d'ouvrir le fichier ");
            return;
        }

        string line;
        while (getline(file, line)) 
        {
            istringstream iss(line);
            string name, seat;

            getline(iss, name, ';');

            getline(iss, seat, ';');
            int seatingCapacity = stoi(seat); 

            addClassroom(name, seatingCapacity);
            
        }

        file.close();
    }

    void Timetable::exportProfessorTimetable(int id) 
    {
        // Trouver le professeur par ID
        Professor professor = findProfessorById(id);
        if (professor.getId() == -1) 
        {
            perror("Professeur non trouvé");
            return;
        }

        // Nom du fichier basé sur le nom du professeur
        string filename = professor.getLastName() + "_" + professor.getFirstName() + ".hor";
        
        // Ouvrir le fichier
        ofstream file(filename);
        if (!file) 
        {
            perror("Erreur lors de la création du fichier");
            return;
        }

        // En-tête
        file << "Horaire de " << professor.getLastName() << " " << professor.getFirstName() << " :\n\n";

        // Parcourir les cours et écrire ceux associés au professeur
        for (const auto& course : courses) 
        {
            if (course.getProfessorId() == id) 
            {
                file << course.getTiming().getDay() << "\t";
                file << course.getTiming().getStart().toString() << "\t";
                file << course.getTiming().getDuration().toString() << "\t";
                file << findClassroomById(course.getClassroomId()).getName() << "\t";
                file << course.getTitle() << "\t";

                // Groupes associés
                bool first = true;
                for (int groupId : course.getGroupsIds()) 
                {
                    if (!first) file << ", ";
                    file << findGroupById(groupId).getName();
                    first = false;
                }
                file << "\n";
            }
        }

        file.close();
    }

    void Timetable::exportGroupTimetable(int id) 
    {
        // Trouver le groupe par ID
        Group group = findGroupById(id);
        if (group.getId() == -1) 
        {
            perror("Groupe non trouvé");
            return;
        }

        // Nom du fichier basé sur le nom du groupe
        string filename = group.getName() + ".hor";
        
        // Ouvrir le fichier
        ofstream file(filename);
        if (!file) 
        {
            perror("Erreur lors de la création du fichier");
            return;
        }

        // En-tête
        file << "Horaire de " << group.getName() << " :\n\n";

        // Parcourir les cours et écrire ceux associés au groupe
        for (const auto& course : courses) 
        {
            if (course.isGroupIdPresent(id)) 
            {
                file << course.getTiming().getDay() << "\t";
                file << course.getTiming().getStart().toString() << "\t";
                file << course.getTiming().getDuration().toString() << "\t";
                file << findClassroomById(course.getClassroomId()).getName() << "\t";
                file << course.getTitle() << "\t";

                // Professeur associé
                file << findProfessorById(course.getProfessorId()).getLastName() << " ";
                file << findProfessorById(course.getProfessorId()).getFirstName() << "\n";
            }
        }

        file.close();
    }

    void Timetable::exportClassroomTimetable(int id) 
    {
        // Trouver le local par ID
        Classroom classroom = findClassroomById(id);
        if (classroom.getId() == -1) 
        {
            perror("Local non trouvé");
            return;
        }

        // Nom du fichier basé sur le nom du local
        string filename = classroom.getName() + ".hor";
        
        // Ouvrir le fichier
        ofstream file(filename);
        if (!file) 
        {
            perror("Erreur lors de la création du fichier");
            return;
        }

        // En-tête
        file << "Horaire de " << classroom.getName() << " :\n\n";

        // Parcourir les cours et écrire ceux associés au local
        for (const auto& course : courses) 
        {
            if (course.getClassroomId() == id) 
            {
                file << course.getTiming().getDay() << "\t";
                file << course.getTiming().getStart().toString() << "\t";
                file << course.getTiming().getDuration().toString() << "\t";
                file << course.getTitle() << "\t";

                // Professeur associé
                file << findProfessorById(course.getProfessorId()).getLastName() << " ";
                file << findProfessorById(course.getProfessorId()).getFirstName() << "\t";

                // Groupes associés
                bool first = true;
                for (int groupId : course.getGroupsIds()) 
                {
                    if (!first) file << ", ";
                    file << findGroupById(groupId).getName();
                    first = false;
                }
                file << "\n";
            }
        }

        file.close();
    }
}
