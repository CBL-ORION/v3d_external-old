#include "Entity.h"
#include "EntityData.h"
#include <QtGui>

Entity::Entity() : id(0), name(0), user(0), entityStatus(0), entityType(0)
{
}

Entity::~Entity()
{
//    qDebug() << "delete entity "<<id<<name;
    if (id != 0) delete id;
    if (name != 0) delete name;
    if (user != 0) delete user;
    if (entityStatus != 0) delete entityStatus;
    if (entityType != 0) delete entityType;

    QSet<EntityData *>::const_iterator i;
    for (i = entityDataSet.begin(); i != entityDataSet.end(); ++i)
    {
        delete *i;
    }
}

bool entityLessThan(const EntityData *e1, const EntityData *e2)
{
    if (e1->orderIndex == NULL)
    {
        if (e2->orderIndex == NULL)
        {
            return *e1->id < *e2->id;
        }
        return true;
    }
    else if (e2->orderIndex == NULL)
    {
        return false;
    }
    return *e1->orderIndex < *e2->orderIndex;
}

QList<EntityData *> Entity::getOrderedEntityData()
{
    QList<EntityData *> list = QList<EntityData *>::fromSet(entityDataSet);
    qSort(list.begin(), list.end(), entityLessThan);
    return list;
}

EntityData* Entity::getEntityDataByAttributeName(const QString & attrName) const
{
    QSet<EntityData *>::const_iterator i;
    for (i = entityDataSet.begin(); i != entityDataSet.end(); ++i)
    {
        EntityData *data = *i;
        if (*data->attributeName == attrName)
        {
            return data;
        }
    }
    return NULL;
}

const QString& Entity::getValueByAttributeName(const QString & attrName) const
{
    EntityData* ed = getEntityDataByAttributeName(attrName);
    if (ed == 0 || ed->value == 0) return QString();
    return *ed->value;
}

void Entity::dumpEntity()
{
    dumpEntity(0);
}

void Entity::dumpEntity(int level)
{
    std::string ind = std::string(level*4, ' ');
    const char * indent = ind.c_str();

    if (id != 0) qDebug("%sEntity.id: %lld",indent,*id);
    if (name != 0) qDebug("%sName: %s",indent,name->toAscii().constData());
    if (user != 0) qDebug("%sUser: %s",indent,user->toAscii().constData());
    if (entityStatus != 0) qDebug("%sStatus: %s",indent,entityStatus->toAscii().constData());
    if (entityType != 0) qDebug("%sType: %s",indent,entityType->toAscii().constData());

    if (!entityDataSet.isEmpty())
    {
        QList<EntityData *> list = getOrderedEntityData();
        QList<EntityData *>::const_iterator i;
        qDebug("%sChildren:",indent);
        for (i = list.begin(); i != list.end(); ++i)
        {
            EntityData *data = *i;
            data->dumpEntityData(level+1);
        }
    }
}
