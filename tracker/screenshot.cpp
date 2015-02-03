
#include <QtWidgets>

#include "screenshot.hpp"

/*initialise les bouton puis prend un screenshot*/
Screenshot::Screenshot()
{
    screenshotLabel = new QLabel;
    screenshotLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    screenshotLabel->setAlignment(Qt::AlignCenter);
    screenshotLabel->setMinimumSize(240, 160);

    createOptionsGroupBox();
    createButtonsLayout();

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(screenshotLabel);
    mainLayout->addWidget(optionsGroupBox);
    mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);

    shootScreen();
    delaySpinBox->setValue(5);

    setWindowTitle(tr("Screenshot"));
    resize(400, 300);
}

/*pas encor compris*/
void Screenshot::resizeEvent(QResizeEvent * /* event */)
{
    QSize scaledSize = originalPixmap.size();
    scaledSize.scale(screenshotLabel->size(), Qt::KeepAspectRatio);
    if (!screenshotLabel->pixmap() || scaledSize != screenshotLabel->pixmap()->size())
        updateScreenshotLabel();
}

/*passe le bouton newScreenButton a true
 puis effectue le callback du bouton (shootscreen())*/
void Screenshot::newScreenshot()
{
    if (hideThisWindowCheckBox->isChecked())
        hide();
    newScreenshotButton->setDisabled(true);

    QTimer::singleShot(delaySpinBox->value() * 1000, this, SLOT(shootScreen()));
}

/*sauvegarde le dernier screenshot pris*/
void Screenshot::saveScreenshot()
{
    QString format = "png";
    QString initialPath = QDir::currentPath() + tr("/untitled.") + format;

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), initialPath,
                                                    tr("%1 Files (*.%2);;All Files (*)")
                                                    .arg(format.toUpper())
                                                    .arg(format));
    if (!fileName.isEmpty())
        originalPixmap.save(fileName, format.toLatin1().constData());
}

/*prend le screenshot. Prend un screenshot du bureau ou prend un image
et l'enregistre dans originalPixmap*/
void Screenshot::shootScreen()
{
    if (delaySpinBox->value() != 0)
        qApp->beep();
    originalPixmap = QPixmap(); // clear image for low memory situations
                                // on embedded devices.
   
    /*recuperation du bureau. ajouter id de la fenetre dans winId, pour recup uniquement celle la*/
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen)
        originalPixmap = screen->grabWindow(QApplication::desktop()->winId());//on peut rqjouter pos x, pos y, width, height
    
    /*recuperer image*/
        // originalPixmap = QPixmap("table_grande2.png");//mettre l'image dans build
    
    updateScreenshotLabel();

    newScreenshotButton->setDisabled(false);
    if (hideThisWindowCheckBox->isChecked())
        show();
}

/*permet de hide (fonctionne pas encor, oup as compris :D)*/
void Screenshot::updateCheckBox()
{
    if (delaySpinBox->value() == 0) {
        hideThisWindowCheckBox->setDisabled(true);
        hideThisWindowCheckBox->setChecked(false);
    } else {
        hideThisWindowCheckBox->setDisabled(false);
    }
}

/*affiche l'image et creer le bouton hide*/
void Screenshot::createOptionsGroupBox()
{
    optionsGroupBox = new QGroupBox(tr("Options"));

    delaySpinBox = new QSpinBox;
    delaySpinBox->setSuffix(tr(" s"));
    delaySpinBox->setMaximum(60);
    connect(delaySpinBox, SIGNAL(valueChanged(int)), this, SLOT(updateCheckBox()));

    delaySpinBoxLabel = new QLabel(tr("Screenshot Delay:"));

    hideThisWindowCheckBox = new QCheckBox(tr("Hide This Window"));

    optionsGroupBoxLayout = new QGridLayout;
    optionsGroupBoxLayout->addWidget(delaySpinBoxLabel, 0, 0);
    optionsGroupBoxLayout->addWidget(delaySpinBox, 0, 1);
    optionsGroupBoxLayout->addWidget(hideThisWindowCheckBox, 1, 0, 1, 2);
    optionsGroupBox->setLayout(optionsGroupBoxLayout);
}

/*creer les bouton new screenshot, sava, print pixel et quit*/
void Screenshot::createButtonsLayout()
{
    newScreenshotButton = createButton(tr("New Screenshot"), this, SLOT(newScreenshot()));
    saveScreenshotButton = createButton(tr("Save Screenshot"), this, SLOT(saveScreenshot()));
    QPushButton *printColorPixel = createButton(tr("print color pixel"), this, SLOT(print_color_pixel2()));
    quitScreenshotButton = createButton(tr("Quit"), this, SLOT(close()));

    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(newScreenshotButton);
    buttonsLayout->addWidget(saveScreenshotButton);
    buttonsLayout->addWidget(printColorPixel);
    buttonsLayout->addWidget(quitScreenshotButton);
}

/*creer le bouton pass en parman
text -> nom du bouton
receiver -> this
member -> SLOT de lq fonction "callback"
*/
QPushButton *Screenshot::createButton(const QString &text, QWidget *receiver,
                                      const char *member)
{
    QPushButton *button = new QPushButton(text);
    button->connect(button, SIGNAL(clicked()), receiver, member);
    return button;
}

/* ??? */
void Screenshot::updateScreenshotLabel()
{
    screenshotLabel->setPixmap(originalPixmap.scaled(screenshotLabel->size(),
                                                     Qt::KeepAspectRatio,
                                                     Qt::SmoothTransformation));
}

/*print la couleur du pixel passer en param*/
void Screenshot::print_color_pixel(int x, int y){
    QImage img = this->originalPixmap.toImage();
    QColor color = img.pixel(x, y);

    std::cout << " red : " << color.red() << std::endl;
    std::cout << " blue : " << color.blue() << std::endl;
    std::cout << " green : " << color.green() << std::endl;
}

/*print la couleur du pixel mis dans le QColor*/
void Screenshot::print_color_pixel2(){
    QImage img = this->originalPixmap.toImage();
    QColor color = img.pixel(150, 150);

    std::cout << " red : " << color.red() << std::endl;
    std::cout << " blue : " << color.blue() << std::endl;
    std::cout << " green : " << color.green() << std::endl;
}