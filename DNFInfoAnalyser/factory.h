#ifndef FACTORY_H
#define FACTORY_H

#include <QMap>
#include <QString>
#include <memory>
#include <QDebug>

template <class Type_t>
class IRegistrar {
  public:
    virtual std::shared_ptr<Type_t> create() = 0;

  protected:
    IRegistrar() {}
    virtual ~IRegistrar() {}

  private:
    IRegistrar(const IRegistrar &);
    const IRegistrar &operator=(const IRegistrar &);
};

template <class Type_t>
class Factory {
  public:
    static Factory<Type_t> &Instance() {
        static Factory<Type_t> instance;
        return instance;
    }

    void Register(IRegistrar<Type_t> *registrar, QString name) {
        m_Registry[name] = registrar;
    }

    std::shared_ptr<Type_t> get(QString name) {
        //qDebug() << "!!! " << name << endl;

        if (m_Registry.find(name) != m_Registry.end()) {
            //qDebug() << "found " << name << endl;
            return m_Registry[name]->create();
        }

        qDebug() << "No product found for " << name << endl;
        return NULL;
    }

    int size() {
        return m_Registry.size();
    }

  private:
    Factory() {}
    ~Factory() {}

    Factory(const Factory &);
    const Factory &operator=(const Factory &);

    QMap<QString, IRegistrar<Type_t> *> m_Registry;
};

template <class Type_t, class Impl_t>
class Registrar : public IRegistrar<Type_t> {
  public:
    explicit Registrar(QString name) {
        Factory<Type_t>::Instance().Register(this, name);
    }

    std::shared_ptr<Type_t> create() {
        return std::shared_ptr<Type_t>(new Impl_t());
    }
};

#endif // FACTORY_H
