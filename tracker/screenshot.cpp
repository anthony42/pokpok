
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
    resize(800, 600);
}

/*creer hash pixel par pixel*/
qint32 Screenshot::hashPixmap(QPixmap pix)
{
    QImage image = pix.toImage();
    qint32 hash = 0;

    for(int y = 0; y < image.height(); y++)
    {
        for(int x = 0; x < image.width(); x++)
        {
            QRgb pixel = image.pixel(x,y);

            hash += pixel;
            hash += (hash << 10);
            hash ^= (hash >> 6);
        }
    }

    return hash;
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

void Screenshot::put_stack_player_1(){
    QPixmap pixmap = originalPixmap;
    QImage  img_tmp = pixmap.toImage();
    QImage  img;

    // QRgb    value;
    // value = qRgb(255, 0, 0);
    int x = img_tmp.size().width() * 0.24428;
    int y = (img_tmp.size().height()-28) * 0.68411;
    // int tmp_x = x;
    // int tmp_y = y+28;
    // while (x < tmp_x+80){
    //     y = tmp_y;
    //     while (y < tmp_y+22){
    //         img_tmp.setPixel(x, y, value);
    //         y++;
    //     }
    //     x++; 
    // }

    // pixmap = pixmap.fromImage(img_tmp);
    // pixmap = pixmap.fromImage(img_tmp.copy(x, y+28, 80, 22));
    pixmap = pixmap.fromImage(img_tmp.copy(x, y+28, img_tmp.size().width() * 0.08316, img_tmp.size().height() * 0.0319303));
    pixmap = color_letter(pixmap);

    originalPixmap = QPixmap(pixmap);
    updateScreenshotLabel();
    if (hideThisWindowCheckBox->isChecked())
        show();
}

void Screenshot::put_stack_player_2(){//player 2
    QPixmap pixmap = originalPixmap;
    QImage  img_tmp = pixmap.toImage();
    QImage  img;

    // QRgb    value;
    // value = qRgb(255, 0, 0);
    int x = img_tmp.size().width() * 0.088357;
    int y = (img_tmp.size().height()-28) * 0.49088;
    // int tmp_x = x;
    // int tmp_y = y+28;
    // while (x < tmp_x+80){
    //     y = tmp_y;
    //     while (y < tmp_y+22){
    //         img_tmp.setPixel(x, y, value);
    //         y++;
    //     }
    //     x++; 
    // }

    // pixmap = pixmap.fromImage(img_tmp);
    // pixmap = pixmap.fromImage(img_tmp.copy(x, y+28, 80, 22));
    pixmap = pixmap.fromImage(img_tmp.copy(x, y+28, img_tmp.size().width() * 0.08316, img_tmp.size().height() * 0.0319303));
    pixmap = color_letter(pixmap);

    originalPixmap = QPixmap(pixmap);
    updateScreenshotLabel();
    if (hideThisWindowCheckBox->isChecked())
        show();
}

void Screenshot::put_stack_player_3(){//player 3
    QPixmap pixmap = originalPixmap;
    QImage  img_tmp = pixmap.toImage();
    QImage  img;

    // QRgb    value;
    // value = qRgb(255, 0, 0);
    int x = img_tmp.size().width() * 0.088357;
    int y = (img_tmp.size().height()-28) * 0.28495;
    // int tmp_x = x;
    // int tmp_y = y+28;
    // while (x < tmp_x+80){
    //     y = tmp_y;
    //     while (y < tmp_y+22){
    //         img_tmp.setPixel(x, y, value);
    //         y++;
    //     }
    //     x++; 
    // }

    // pixmap = pixmap.fromImage(img_tmp);
    // pixmap = pixmap.fromImage(img_tmp.copy(x, y+28, 80, 22));
    pixmap = pixmap.fromImage(img_tmp.copy(x, y+28, img_tmp.size().width() * 0.08316, img_tmp.size().height() * 0.0319303));
    pixmap = color_letter(pixmap);

    originalPixmap = QPixmap(pixmap);
    updateScreenshotLabel();
    if (hideThisWindowCheckBox->isChecked())
        show();
}

void Screenshot::put_stack_player_4(){//player 4
    QPixmap pixmap = originalPixmap;
    QImage  img_tmp = pixmap.toImage();
    QImage  img;

    // QRgb    value;
    // value = qRgb(255, 0, 0);
    int x = img_tmp.size().width() * 0.27651;
    int y = (img_tmp.size().height()-28) * 0.1194;
    // int tmp_x = x;
    // int tmp_y = y+28;
    // while (x < tmp_x+80){
    //     y = tmp_y;
    //     while (y < tmp_y+22){
    //         img_tmp.setPixel(x, y, value);
    //         y++;
    //     }
    //     x++; 
    // }

    // pixmap = pixmap.fromImage(img_tmp);
    // pixmap = pixmap.fromImage(img_tmp.copy(x, y+28, 80, 22));
    pixmap = pixmap.fromImage(img_tmp.copy(x, y+28, img_tmp.size().width() * 0.08316, img_tmp.size().height() * 0.0319303));
    pixmap = color_letter(pixmap);

    originalPixmap = QPixmap(pixmap);
    updateScreenshotLabel();
    if (hideThisWindowCheckBox->isChecked())
        show();
}

void Screenshot::put_stack_player_5(){//player 5
    QPixmap pixmap = originalPixmap;
    QImage  img_tmp = pixmap.toImage();
    QImage  img;

    // QRgb    value;
    // value = qRgb(255, 0, 0);
    int x = img_tmp.size().width() * 0.63722;
    int y = (img_tmp.size().height()-28) * 0.1194;
    // int tmp_x = x;
    // int tmp_y = y+28;
    // while (x < tmp_x+80){
    //     y = tmp_y;
    //     while (y < tmp_y+22){
    //         img_tmp.setPixel(x, y, value);
    //         y++;
    //     }
    //     x++; 
    // }

    // pixmap = pixmap.fromImage(img_tmp);
    // pixmap = pixmap.fromImage(img_tmp.copy(x, y+28, 80, 22));
    pixmap = pixmap.fromImage(img_tmp.copy(x, y+28, img_tmp.size().width() * 0.08316, img_tmp.size().height() * 0.0319303));
    pixmap = color_letter(pixmap);

    originalPixmap = QPixmap(pixmap);
    updateScreenshotLabel();
    if (hideThisWindowCheckBox->isChecked())
        show();
}

void Screenshot::put_stack_player_6(){//player 6
    QPixmap pixmap = originalPixmap;
    QImage  img_tmp = pixmap.toImage();
    QImage  img;

    // QRgb    value;
    // value = qRgb(255, 0, 0);
    int x = img_tmp.size().width() * 0.82744;
    int y = (img_tmp.size().height()-28) * 0.28495;
    // int tmp_x = x;
    // int tmp_y = y+28;
    // while (x < tmp_x+80){
    //     y = tmp_y;
    //     while (y < tmp_y+22){
    //         img_tmp.setPixel(x, y, value);
    //         y++;
    //     }
    //     x++; 
    // }

    // pixmap = pixmap.fromImage(img_tmp);
    // pixmap = pixmap.fromImage(img_tmp.copy(x, y+28, 80, 22));

    pixmap = pixmap.fromImage(img_tmp.copy(x, y+28, img_tmp.size().width() * 0.08316, img_tmp.size().height() * 0.0319303));
    pixmap = color_letter(pixmap);

    originalPixmap = QPixmap(pixmap);
    updateScreenshotLabel();
    if (hideThisWindowCheckBox->isChecked())
        show();
}

void Screenshot::put_stack_player_7(){//player 7
    QPixmap pixmap = originalPixmap;
    QImage  img_tmp = pixmap.toImage();
    QImage  img;

    // QRgb    value;
    // value = qRgb(255, 0, 0);
    int x = img_tmp.size().width() * 0.82744;
    int y = (img_tmp.size().height()-28) * 0.49088;
    // int tmp_x = x;
    // int tmp_y = y+28;
    // while (x < tmp_x+80){
    //     y = tmp_y;
    //     while (y < tmp_y+22){
    //         img_tmp.setPixel(x, y, value);
    //         y++;
    //     }
    //     x++; 
    // }

    // pixmap = pixmap.fromImage(img_tmp);
    // pixmap = pixmap.fromImage(img_tmp.copy(x, y+28, 80, 22));
    pixmap = pixmap.fromImage(img_tmp.copy(x, y+28, img_tmp.size().width() * 0.08316, img_tmp.size().height() * 0.0319303));
    pixmap = color_letter(pixmap);

    originalPixmap = QPixmap(pixmap);
    updateScreenshotLabel();
    if (hideThisWindowCheckBox->isChecked())
        show();
}

void Screenshot::put_stack_player_8(){//player 8
    QPixmap pixmap = originalPixmap;
    QImage  img_tmp = pixmap.toImage();
    QImage  img;

    // QRgb    value;
    // value = qRgb(255, 0, 0);
    int x = img_tmp.size().width() * 0.67048;
    int y = (img_tmp.size().height()-28) * 0.68411;
    // int tmp_x = x;
    // int tmp_y = y+28;
    // while (x < tmp_x+80){
    //     y = tmp_y;
    //     while (y < tmp_y+22){
    //         img_tmp.setPixel(x, y, value);
    //         y++;
    //     }
    //     x++; 
    // }
    
    // pixmap = pixmap.fromImage(img_tmp);
    pixmap = pixmap.fromImage(img_tmp.copy(x, y+28, img_tmp.size().width() * 0.08316, img_tmp.size().height() * 0.0319303));
    pixmap = color_letter(pixmap);

    originalPixmap = QPixmap(pixmap);
    updateScreenshotLabel();
    if (hideThisWindowCheckBox->isChecked())
        show();
}

char    Screenshot::take_number(QPixmap letre){
    QColor color;
    QImage img = letre.toImage();
    int height = img.size().height()-1;
    int width = img.size().width()-1;

    if (height < 7)
        return ',';
    color = img.pixel(width, 0);//pixel en haut a droite
    // std::cout << " 1 5 7 red : " << color.red() << " black: " << color.black() << std::endl;
    if (color.black() < color.red()){//possibiliter 1 5 7
        color = img.pixel(width, height);//en bas a droite
        // std::cout << " 1 red : " << color.red() << " black: " << color.black() << std::endl;
        if (color.black() < color.red()){
            return '1';
        }
        color = img.pixel(0, height-1);//en bas a gauche remonter de 1 px
        // std::cout << " 5 7 red : " << color.red() << " black: " << color.black() << std::endl;
        if (color.black() < color.red()){
            return '5';
        }
        else
            return '7';
    }
    color = img.pixel(width, height);//en bas a droite
    // std::cout << " 2 red : " << color.red() << " black: " << color.black() << std::endl;
    if (color.black() < color.red()){
        return '2';
    }
    color = img.pixel(width/2, (height/2) -2);
    // std::cout << " 8 3 4 red : " << color.red() << " black: " << color.black() << std::endl;
    if (color.black() < color.red()){
        color = img.pixel(0, 1);
        // std::cout << " 8 3 red : " << color.red() << " black: " << color.black() << std::endl;
        if (color.black() > color.red()){
            return '4';
        }
    }
    color = img.pixel(width, 4);
    // std::cout << "9 0 red : " << color.red() << " black: " << color.black() << std::endl;
    if (color.black() < color.red()){
        color = img.pixel(4, height);
        if (color.black() < color.red()){
            color = img.pixel(width/2, (height/2) -1);
            if (color.black() > color.red()){
                return '0';
            }
        }
        else
            return '9';
    }
    color = img.pixel(1, height/2 -1);
    if (color.black() < color.red()){
        color = img.pixel(2, height/2 -1);
        if (color.black() < color.red()){
            color = img.pixel(3, height/2 -1);
            if (color.black() < color.red()){
                color = img.pixel(4, height/2 -1);
                if (color.black() < color.red()){
                    color = img.pixel(0, 3);
                    if (color.black() < color.red()){
                        return '6';
                    }
                    else
                        return '8';
                }
            }
        }
    }
    
    return 'N';
}

QPixmap Screenshot::color_letter(QPixmap pixmap) {
    int x = 0;
    int count = 0;
    int & ref_to_x = x;
    char c;
    std::string stack;
    QImage img = pixmap.toImage();
    QPixmap letre;
    while (x < img.size().width()){
        count++;
        letre = take_letter(pixmap, ref_to_x);
        std::cout << count << " eme nombre" << std::endl;
        c = take_number(letre);

        stack += c;
        x++;
        // if (count == 1)//recuperer le x eme nombre , prend en compte la virgule comme nb
            // break;
    }
    int i = stack.size();
    stack[i] = 0;
    stack[i-1] = 0;
    stack[i-2] = 0;
    std::cout << "stack: " << stack << std::endl;
    // pixmap = letre;
    // letre = take_letter(pixmap, x);
    // std::cout << "x: " << x << std::endl;
    return pixmap;
}

QPixmap Screenshot::take_letter(QPixmap pixmap, int & x){
    int y = 0;
    bool in_color = false;
    int haut = 0;
    int bas = 0;
    int droite = 0;
    int gauche = 0;
    QImage img = pixmap.toImage();
    QRgb   red;

    red = qRgb(255, 0 , 0);
    while (x < img.size().width()){
        y = 0;
        in_color = false;
        while (y < img.size().height()){
            QColor color= img.pixel(x, y);
            if (color.black() < color.green())
            {
                if (in_color == false)
                    in_color = true;
                img.setPixel(x, y, red);
                if (haut > y || haut == 0)
                    haut = y;
                if (bas <= y)
                    bas = y+1;
            }
            y++;
        }
        if (in_color == true && gauche > 0)
            droite = x + 1;
        if (in_color == true && gauche == 0)
            gauche = x;
        if (droite > 0 && gauche > 0 && haut > 0 && bas > 0 && in_color == false)
            break;
       x++;
    }
    // std::cout << "haut: " << haut << " bas: " << bas << " gauche: " << gauche << " droite: " << droite << std::endl;
    pixmap = pixmap.fromImage(img.copy(gauche, haut , droite - gauche, bas - haut));//recupere la 1ere letre
    // pixmap = pixmap.fromImage(img.copy());//recupere tous le montant
    return pixmap;
}

/* affiche un carre de 10*10 pixel noir a l'endroit ou il y as les carte*/
void Screenshot::put_pixel_black(){
    QRgb    value;
    QPixmap pixmap = originalPixmap;
    QImage  img = pixmap.toImage();

    /*le 28 corespond a la barre en haut qui change pas de taile*/
    value = qRgb(0, 0, 0);
    std::cout << "height : " << img.size().height() << std::endl;
    std::cout << "width : " << img.size().width() << std::endl;
    /* carte du joueur 1 */
    int x = img.size().width() * 0.28266;//28.066%
    int y = (img.size().height()-28) * 0.56655;//58.055%
    int tmp_x = x;
    int tmp_y = y+28;
    while (x < tmp_x+10){
        y = tmp_y;
        while (y < tmp_y+10){
            img.setPixel(x, y, value);
            y++;
        }
        x++;
    }
    /*carte joueeur 2*/
    x = img.size().width() * 0.2079;
    y = (img.size().height()-28) * 0.45169;
    tmp_x = x;
    tmp_y = y+28;
    while (x < tmp_x+10){
        y = tmp_y;
        while (y < tmp_y+10){
            img.setPixel(x, y, value);
            y++;
        }
        x++;
    }
    /*carte joueur 3*/
    x = img.size().width() * 0.21829;
    y = (img.size().height()-28) * 0.28894;
    tmp_x = x;
    tmp_y = y+28;
    while (x < tmp_x+10){
        y = tmp_y;
        while (y < tmp_y+10){
            img.setPixel(x, y, value);
            y++;
        }
        x++;
    }
    /*carte joueur 4*/
    x = img.size().width() * 0.3398;
    y = (img.size().height()-28) * 0.19041;
    tmp_x = x;
    tmp_y = y+28;
    while (x < tmp_x+10){
        y = tmp_y;
        while (y < tmp_y+10){
            img.setPixel(x, y, value);
            y++;
        }
        x++;
    }
    /*carte joueur 5*/
    x = img.size().width() * 0.65748;
    y = (img.size().height()-28) * 0.19041;
    tmp_x = x;
    tmp_y = y+28;
    while (x < tmp_x+10){
        y = tmp_y;
        while (y < tmp_y+10){
            img.setPixel(x, y, value);
            y++;
        }
        x++;
    }
    /*carte joueur 6*/
    x = img.size().width() * 0.77241;
    y = (img.size().height()-28) * 0.28671;
    tmp_x = x;
    tmp_y = y+28;
    while (x < tmp_x+10){
        y = tmp_y;
        while (y < tmp_y+10){
            img.setPixel(x, y, value);
            y++;
        }
        x++;
    }
    /*carte joueur 7*/
    x = img.size().width() * 0.78502;
    y = (img.size().height()-28) * 0.47169;
    tmp_x = x;
    tmp_y = y+28;
    while (x < tmp_x+10){
        y = tmp_y;
        while (y < tmp_y+10){
            img.setPixel(x, y, value);
            y++;
        }
        x++;
    }
    /*carte joueur 8*/
    x = img.size().width() * 0.69499;
    y = (img.size().height()-28) * 0.56789;
    tmp_x = x;
    tmp_y = y+28;
    while (x < tmp_x+10){
        y = tmp_y;
        while (y < tmp_y+10){
            img.setPixel(x, y, value);
            y++;
        }
        x++;
    }

    pixmap = pixmap.fromImage(img);
    originalPixmap = QPixmap(pixmap);
    updateScreenshotLabel();
    if (hideThisWindowCheckBox->isChecked())
        show();
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

/*affiche la petite table*/
void Screenshot::put_small_screen(){
    if (delaySpinBox->value() != 0)
        qApp->beep();
    originalPixmap = QPixmap();

    // originalPixmap = QPixmap("/nfs/zfs-student-5/users/2013/aelola/perso/tracker/build-tracker-Desktop_Qt_5_4_0_MinGW_32bit-Debug/table_petite2.png");//mettre l'image dans build
    originalPixmap = QPixmap("table_petite2.png");
    // std::cout << hashPixmap(originalPixmap) << std::endl;
    updateScreenshotLabel();

    newScreenshotButton->setDisabled(false);
    if (hideThisWindowCheckBox->isChecked())
        show();
}

/*affiche la grande table*/
void Screenshot::put_big_screen(){
    if (delaySpinBox->value() != 0)
        qApp->beep();
    // originalPixmap = QPixmap();

    // originalPixmap = QPixmap("/nfs/zfs-student-5/users/2013/aelola/perso/tracker/build-tracker-Desktop_Qt_5_4_0_MinGW_32bit-Debug/table_grande2.png");//mettre l'image dans build
    originalPixmap = QPixmap("table_grande2.png");
    // std::cout << hashPixmap(originalPixmap) << std::endl;
    updateScreenshotLabel();

    newScreenshotButton->setDisabled(false);
    if (hideThisWindowCheckBox->isChecked())
        show();
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
       originalPixmap = screen->grabWindow(QApplication::desktop()->winId());//on peut rajouter pos x, pos y, width, height apres winid(),

    /*recuperer image*/
    // originalPixmap = QPixmap("/nfs/zfs-student-5/users/2013/aelola/perso/tracker/build-tracker-Desktop_Qt_5_4_0_MinGW_32bit-Debug/table_petite2.png");//mettre l'image dans build

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
    QPushButton *smallscreen = createButton(tr("Small screen"), this, SLOT(put_small_screen()));
    QPushButton *bigScreen = createButton(tr("Big screen"), this, SLOT(put_big_screen()));
    QPushButton *stackPlayer1 = createButton(tr("stack player 1"), this, SLOT(put_stack_player_1()));//ligne 71
    QPushButton *stackPlayer2 = createButton(tr("stack player 2"), this, SLOT(put_stack_player_2()));//ligne 71
    QPushButton *stackPlayer3 = createButton(tr("stack player 3"), this, SLOT(put_stack_player_3()));//ligne 71
    QPushButton *stackPlayer4 = createButton(tr("stack player 4"), this, SLOT(put_stack_player_4()));//ligne 71
    QPushButton *stackPlayer5 = createButton(tr("stack player 5"), this, SLOT(put_stack_player_5()));//ligne 71
    QPushButton *stackPlayer6 = createButton(tr("stack player 6"), this, SLOT(put_stack_player_6()));//ligne 71
    QPushButton *stackPlayer7 = createButton(tr("stack player 7"), this, SLOT(put_stack_player_7()));//ligne 71
    QPushButton *stackPlayer8 = createButton(tr("stack player 8"), this, SLOT(put_stack_player_8()));//ligne 71
    putPixelBlack = createButton(tr("put pixel black"), this, SLOT(put_pixel_black()));
    quitScreenshotButton = createButton(tr("Quit"), this, SLOT(close()));

    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(newScreenshotButton);
    buttonsLayout->addWidget(saveScreenshotButton);
    buttonsLayout->addWidget(printColorPixel);
    buttonsLayout->addWidget(putPixelBlack);
    buttonsLayout->addWidget(smallscreen);
    buttonsLayout->addWidget(bigScreen);
    buttonsLayout->addWidget(stackPlayer1);
    buttonsLayout->addWidget(stackPlayer2);
    buttonsLayout->addWidget(stackPlayer3);
    buttonsLayout->addWidget(stackPlayer4);
    buttonsLayout->addWidget(stackPlayer5);
    buttonsLayout->addWidget(stackPlayer6);
    buttonsLayout->addWidget(stackPlayer7);
    buttonsLayout->addWidget(stackPlayer8);
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

/* met a jour l'image afficher dans la fenetre */
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
