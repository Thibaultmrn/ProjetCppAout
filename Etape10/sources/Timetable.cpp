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
}
