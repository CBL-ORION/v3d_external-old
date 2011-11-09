#ifndef DATATHREAD_H
#define DATATHREAD_H

#include "../../webservice/console/cdsConsoleDataServiceProxy.h"
#include "../entity_model/AnnotatedBranch.h"
#include <QObject>
#include <QThread>
#include <QHash>

class OntologyAnnotation;

class DataThread : public QThread
{
    Q_OBJECT

public:
    explicit DataThread(QObject *parent = 0);
    ~DataThread();
    void run();
    // Let the thread continue running (since we have no way to interrupt it)
    // but disregard all subsequent signals, and have it clean up its own memory
    // when it's done.
    void disregard();

signals:
    // The caller must listen for this signal and take responsibility for the
    // memory management of the parameter object (results).
    void gotResults(const void *results);
    // The caller must listen for this signal in order to be notified when the
    // thread finishes with an error condition.
    void gotError(const QString & message);

protected:
    void *results;
    QString *errorMessage;
    cds::ConsoleDataServiceProxy proxy;
    virtual void fetchData() = 0;
};

// ===========================================================
// Get Ontology Tree
// ===========================================================

class GetOntologyThread : public DataThread
{
    Q_OBJECT

public:
    explicit GetOntologyThread(qint64 entityId, QObject *parent = 0);
    void fetchData();
private:
    qint64 entityId;
};

// ===========================================================
// Get AnnotatedBranch
// ===========================================================

class GetAnnotatedBranchThread : public DataThread
{
    Q_OBJECT

public:
    explicit GetAnnotatedBranchThread(qint64 entityId, QObject *parent = 0);
    void fetchData();
private:
    void fetchAnnotations(Entity *entity, QHash<QString, QColor> *userColorMap);
    QHash<qint64, AnnotationList*> *annotationMap;
    qint64 entityId;
};

// ===========================================================
// Get Entity
// ===========================================================

class GetEntityThread : public DataThread
{
    Q_OBJECT

public:
    explicit GetEntityThread(qint64 entityId, QObject *parent = 0);
    void fetchData();
private:
    qint64 entityId;
};

// ===========================================================
// Get Entity Annotations
// ===========================================================

class GetEntityAnnotationsThread : public DataThread
{
    Q_OBJECT

public:
    explicit GetEntityAnnotationsThread(qint64 entityId, QObject *parent = 0);
    void fetchData();
    inline qint64 getEntityId() const { return entityId; }
    QHash<QString, QColor> * getUserColorMap() const { return userColorMap; }
private:
    qint64 entityId;
    QHash<QString, QColor> *userColorMap;
};

// ===========================================================
// Create Annotation
// ===========================================================

class CreateAnnotationThread : public DataThread
{
    Q_OBJECT

public:
    explicit CreateAnnotationThread(OntologyAnnotation *annotation, QObject *parent = 0);
    ~CreateAnnotationThread();
    void fetchData();
    qint64* getTargetEntityId() const;

private:
    OntologyAnnotation *annotation;
};

// ===========================================================
// Remove Annotation
// ===========================================================

class RemoveAnnotationThread : public DataThread
{
    Q_OBJECT

public:
    explicit RemoveAnnotationThread(qint64 annotationId, QObject *parent = 0);
    void fetchData();

private:
    qint64 annotationId;
};

// ===========================================================
// Get Annotation Session
// ===========================================================

class GetAnnotationSessionThread : public DataThread
{
    Q_OBJECT

public:
    explicit GetAnnotationSessionThread(qint64 sessionId, QObject *parent = 0);
    void fetchData();

private:
    qint64 sessionId;
};


// ===========================================================
// Select Entity
// ===========================================================

class SelectEntityThread : public DataThread
{
    Q_OBJECT

public:
    explicit SelectEntityThread(qint64 entityId, QObject *parent = 0);
    void fetchData();

private:
    qint64 entityId;
};



#endif // DATATHREAD_H
