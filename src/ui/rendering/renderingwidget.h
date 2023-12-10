#ifndef RENDERINGWIDGET_H
#define RENDERINGWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>


class RenderingWidget : public QOpenGLWidget, protected QOpenGLFunctions {
	Q_OBJECT

public:
    RenderingWidget(QWidget *parent = nullptr);

	virtual ~RenderingWidget() override;


protected:
	virtual void initializeGL() override;

	virtual void resizeGL(int w, int h) override;

	virtual void paintGL() override;

    virtual void mouseReleaseEvent(QMouseEvent *event) override;

	void initPBO();



private:
	GLuint m_tbo;
    GLuint m_pbo;
};

#endif // RENDERINGWIDGET_H
