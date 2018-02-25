#ifndef ZSOFTINFODIA_H
#define ZSOFTINFODIA_H

#include <QDialog>
#include <QToolButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QGridLayout>
#include <QProcess>
class ZSoftInfoDia : public QDialog
{
    Q_OBJECT
public:
    ZSoftInfoDia(QWidget *parent=0);
    ~ZSoftInfoDia();
private slots:
    void ZSlotOkay();
    void ZSlotCancel();
    void ZSlotReadProcessResult(int exitCode);
private:
    QLabel *m_llAppName;
    QLineEdit *m_leAppName;
    QLabel *m_llVersion;
    QLineEdit *m_leVersion;
    QLabel *m_llMachineNo;
    QLineEdit *m_leMachineNo;
    QLabel *m_llRegisterNo;
    QTextEdit *m_teRegisterNo;
    QToolButton *m_tbOkay;
    QToolButton *m_tbCancel;
    QGridLayout *m_gridLayout;

    QProcess *m_process;
};

#endif // ZSOFTINFODIA_H
