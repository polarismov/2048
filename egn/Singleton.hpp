#ifndef EGN_SINGLETON_HPP
#define EGN_SINGLETON_HPP


template<class T>
class Singleton
{
public:
    static void init()
    {
        if( _singleton == 0 )
        {
            _singleton = new T();
        }
    }

    static T* get()
    {
        if( _singleton == 0 ) init();
        return static_cast<T*>(_singleton);
    }

    static void kill()
    {
        if( _singleton == 0 )
        {
            delete _singleton;
            _singleton = 0;
        }
    }

protected:
    Singleton() {}
    virtual ~Singleton() {}

    static T* _singleton;
};


template<class T>
T* Singleton<T>::_singleton = 0;


#endif
