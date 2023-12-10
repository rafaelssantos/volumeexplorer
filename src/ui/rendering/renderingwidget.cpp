#include "renderingwidget.h"


#include "renderinguicontroller.h"
#include "settings/renderingsettings.h"

using namespace settings;


RenderingWidget::RenderingWidget(QWidget *parent) : QOpenGLWidget (parent) {
    m_pbo = 0;
    m_tbo = 0;
}





RenderingWidget::~RenderingWidget() {

}



void RenderingWidget::initializeGL() {
    initializeOpenGLFunctions();
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}





void RenderingWidget::resizeGL(int w, int h) {
    initPBO();

    glViewport(0, 0, w, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, w, 0.0, h, 0.0, 1.0);
}





void RenderingWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);

    RenderingUIController::instance().slotRender(width(), height());

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, m_pbo);
    glBindTexture(GL_TEXTURE_RECTANGLE_ARB, m_tbo);
    glTexSubImage2D(GL_TEXTURE_RECTANGLE_ARB, 0, 0, 0, width(), height(), GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, 0);

    glEnable(GL_TEXTURE_RECTANGLE_ARB);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex2f(0, 0);

    glTexCoord2f(width(), 0);
    glVertex2f(width(), 0);

    glTexCoord2f(width(), height());
    glVertex2f(width(), height());

    glTexCoord2f(0, height());
    glVertex2f(0, height());
    glEnd();
    glDisable(GL_TEXTURE_RECTANGLE_ARB);
    glBindTexture(GL_TEXTURE_RECTANGLE_ARB, 0);

    frameSwapped();
}





void RenderingWidget::initPBO() {
    if (m_pbo) {
        RenderingUIController::instance().slotUnregisterGlPBOAsResource();
        glDeleteBuffers(1, &m_pbo);
        glDeleteTextures(1, &m_tbo);
    }
    glGenBuffers(1, &m_pbo);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, m_pbo);
	glBufferData(GL_PIXEL_UNPACK_BUFFER_ARB, width() * height() * 4 * sizeof(GLubyte), nullptr, GL_DYNAMIC_DRAW_ARB);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER_ARB, 0);

    RenderingUIController::instance().slotRegisterGlPBOAsResource(m_pbo);

    glGenTextures(1, &m_tbo);
    glBindTexture(GL_TEXTURE_RECTANGLE_ARB, m_tbo);
    glTexImage2D(GL_TEXTURE_RECTANGLE_ARB, 0, GL_RGBA8, width(), height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_RECTANGLE_ARB, 0);
}


void RenderingWidget::mouseReleaseEvent(QMouseEvent *event){
    RenderingUIController::instance().slotUpdate();
}
