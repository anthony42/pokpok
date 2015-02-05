#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include "../tesseract-mingw-master/include/leptonica/allheaders.h"
#include "../tesseract-mingw-master/include/tesseract/apitypes.h"
#include <iostream>
#include <QPixmap>
#include <QWidget>
#include <QRgb>

class QCheckBox;
class QGridLayout;
class QGroupBox;
class QHBoxLayout;
class QLabel;
class QPushButton;
class QSpinBox;
class QVBoxLayout;

class Screenshot : public QWidget
{
    Q_OBJECT
public:
    Screenshot();
    void print_color_pixel(int x, int y);

protected:
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

private slots:
    void print_color_pixel2();
    void newScreenshot();
    void saveScreenshot();
    void shootScreen();
    void updateCheckBox();
    void put_pixel_black();
    void put_big_screen();
    void put_small_screen();
    void put_stack_player_1();

private:

    qint32 hashPixmap(QPixmap pix);
    void createOptionsGroupBox();
    void createButtonsLayout();
    QPushButton *createButton(const QString &text, QWidget *receiver, const char *member);
    void updateScreenshotLabel();

    QPixmap originalPixmap;

    QLabel *screenshotLabel;
    QGroupBox *optionsGroupBox;
    QSpinBox *delaySpinBox;
    QLabel *delaySpinBoxLabel;
    QCheckBox *hideThisWindowCheckBox;
    QPushButton *newScreenshotButton;
    QPushButton *saveScreenshotButton;
    QPushButton *quitScreenshotButton;
    QPushButton *putPixelBlack;

    QVBoxLayout *mainLayout;
    QGridLayout *optionsGroupBoxLayout;
    QHBoxLayout *buttonsLayout;
};

#endif // SCREENSHOT_H
