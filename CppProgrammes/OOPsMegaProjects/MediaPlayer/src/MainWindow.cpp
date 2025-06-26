#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    ui->volumeSlider->setValue(50);
    audioOutput->setVolume(0.5);

    connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::playMusic);
    connect(ui->pauseButton, &QPushButton::clicked, player, &QMediaPlayer::pause);
    connect(ui->stopButton, &QPushButton::clicked, player, &QMediaPlayer::stop);
    connect(ui->volumeSlider, &QSlider::valueChanged, [this](int value) {
        audioOutput->setVolume(value / 100.0);
    });

    ui->nowPlayingLabel->setText("Now Playing: None");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::playMusic() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Audio"), "", tr("Audio Files (*.mp3 *.wav *.ogg)"));
    if (!fileName.isEmpty()) {
        player->setSource(QUrl::fromLocalFile(fileName));
        player->play();
        ui->nowPlayingLabel->setText("Now Playing: " + QFileInfo(fileName).fileName());
    }
}
