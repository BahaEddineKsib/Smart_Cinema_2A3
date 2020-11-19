#ifndef CURRENT_USER_H
#define CURRENT_USER_H

#include <qstring.h>

class current_user
{
    static current_user *Instance;
    current_user();
    public:
        static current_user *get()
        {
            if(!Instance)
                Instance = new current_user();
            return Instance;
        }
        virtual ~current_user();
        int id;
        int role;
        QString username;
        QString password;
        QString f_name;
        QString l_name;
        int online;

        void reset();

        void setUser(int id);

    protected:

    private:

};






#endif // CURRENT_USER_H
