#ifndef CRAZYCUBEGL_H
#define CRAZYCUBEGL_H

#include <QGLWidget>

class CrazyCubeGL : public QGLWidget
{
    Q_OBJECT
public:
    explicit CrazyCubeGL(QWidget *parent = 0);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);


public slots:


signals:


};

#endif // CRAZYCUBEGL_H
