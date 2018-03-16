#ifndef PTEMPLATEEDITOR_H
#define PTEMPLATEEDITOR_H

#include <QWidget>
#include <QToolButton>
#include <QTreeWidget>
#include <QSplitter>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QMenu>
#include <QTabWidget>
#include <QComboBox>
#include "Sheet/zsheet.h"
#include "pgblpara.h"
//#include <QtXlsx/QtXlsx>
class ZTabWidget:public QFrame
{
    Q_OBJECT
public:
    virtual QString ZGetWidgetTypeName()=0;
};
class ZTemplateWidget:public ZTabWidget
{
    Q_OBJECT
public:
    ZTemplateWidget();
    ~ZTemplateWidget();
    QString ZGetWidgetTypeName();

signals:
    void ZSignalOpenTemplate(QString templateName);
    void ZSignalOpenVarSource(QString varSourceName);
private slots:
    void ZSlotTemplateTreeDoubleClicked(QModelIndex index);
    void ZSlotVarSourceTreeDoubleClicked(QModelIndex index);
public:
    QTreeWidget *m_treeWidget;
    QTreeWidget *m_treeVarSource;
    QSplitter *m_splitter;
    QVBoxLayout *m_vLayout;
};

class ZSheetWidget:public ZTabWidget
{
    Q_OBJECT
public:
    ZSheetWidget();
    ~ZSheetWidget();
    QString ZGetWidgetTypeName();

    //get or put template xml data on qtablewidget.
    QString ZGetTemplateXmlData();
    void ZPutTemplateXmlData(QString xmlData);

    void ZPutVarSourceXmlData(QString xmlData);
signals:
    void ZSignalDataChanged(QString templateName);
    void ZSignalFontChanged(QString fontFamily,qint32 fontSize,bool bold,bool italic);
    void ZSignalAlignmentChanged(qint32 alignNo);
    void ZSignalMergeCell();
    void ZSignalSplitCell();
    void ZSignalAddPic();
    void ZSignalDelPic();
private slots:
    void ZSlotVarDblClicked(QTreeWidgetItem*item,int column);
    void ZSlotFontChanged();
    void ZSlotAlignmentChanged();
    void ZSlotMergeSplitCell();
    void ZSlotAddDelPic();
    void ZSlotUpdateFontSize(QString fontFamily);
    void ZSlotCellActivated(qint32 x,qint32 y);
public:

    ZSheet *m_sheet;
    //////////////////////////
    QTreeWidget *m_treeWidget;

    //line 1.
    QComboBox *m_cbFontFamily;
    QComboBox *m_cbFontSize;
    QToolButton *m_tbBold;
    QToolButton *m_tbItalic;
    //line 2.
    QToolButton *m_tbAlignCenter;
    QToolButton *m_tbAlignLeft;
    QToolButton *m_tbAlignHCenter;
    QToolButton *m_tbAlignRight;
    QToolButton *m_tbAlignTop;
    QToolButton *m_tbAlignVCenter;
    QToolButton *m_tbAlignBottom;
    //line3.
    QToolButton *m_tbMerge;
    QToolButton *m_tbSplit;
    QToolButton *m_tbAddPic;
    QToolButton *m_tbDelPic;
    QLineEdit *m_leXY;

    QGridLayout *m_gLayoutBtn;

    QFrame *m_frmBottom;
    QHBoxLayout *m_hLayoutBottom;
    QSplitter *m_spliter;
    QVBoxLayout *m_vLayout;

    QTreeWidgetItem *m_generalVarItem;
    QTreeWidgetItem *m_autoVarItem;
};

class PTemplateEditor : public QFrame,public ZAckNetFrmWidget
{
    Q_OBJECT
public:
    explicit PTemplateEditor(QWidget *parent = 0);
    ~PTemplateEditor();

    void ZProcessAckNetFrm(QString item,QString cmd,QStringList paraList,qint32 ackNetRetCode);
protected:
    void closeEvent(QCloseEvent *event);
signals:
    void ZSignalCloseEvent(QString widget);
    void ZSignalLogMsg(QString logMsg);
public slots:
    void ZSlotNewTemplate();
    void ZSlotOpenTemplate();
    void ZSlotOpenTemplate(QString templateName);
    void ZSlotSaveTemplate();
    void ZSlotSaveAsTemplate();
    void ZSlotDelTemplate();
    void ZSlotBindVarSource();
    void ZSlotUnbindVarSource();

    void ZSlotImportTemplate();
    void ZSlotExportTemplate();
    void ZSlotImportExcel();
    void ZSlotExportExcel();

    void ZSlotInsertPic();
    void ZSlotRemovePic();
    void ZSlotMergeCell();
    void ZSlotSplitCell();
    void ZSlotCellFont();
    void ZSlotCellColor();
    void ZSlotCellFrame();
    void ZSlotCellBindVar();
    void ZSlotCellUnbindVar();
    void ZSlotFontChanged(QString fontFamily,qint32 fontSize,bool bold,bool italic);

    void ZSlotHAlignLeft();
    void ZSlotHAlignCenter();
    void ZSlotHAlignRight();
    void ZSlotVAlignTop();
    void ZSlotVAlignCenter();
    void ZSlotVAlignBottom();
    void ZSlotAlignmentChanged(qint32 alignNo);

    void ZSlotSysPic1();
    void ZSlotSysPic2();
    void ZSlotSysPic3();

    void ZSlotInsertCheckBox();
    void ZSlotInsertComboBox();
    void ZSlotInsertSpinBox();
    void ZSlotInsertDateTimeEdit();

    void ZSlotAddVarSource();
    void ZSlotDelVarSource();
    void ZSlotOpenVarSource();
    void ZSlotOpenVarSource(QString varSourceName);
    void ZSlotExportVarSourceTemplate();
    void ZSlotImportVarSource();

    void ZSlotRemoveTab(qint32 index);
    void ZSlotSheetDataChanged(QString templateName);

    void ZSlotPrintHtml();
    void ZSlotPrintPdf();
    void ZSlotPrint();

    void ZSlotHelp();

    void ZSlotTemplateTreePopupMenu(const QPoint &pt);
    void ZSlotVarSourceTreePopupMenu(const QPoint &pt);
private:
    void ZSetTextAlignment(qint32 alignment);
    void ZAddLogMsg(QString logMsg);
private:
    //left.
    QVBoxLayout *m_vLayoutBtns;

    QToolButton *m_btnTemplate;
    QMenu *m_menuTemplate;
    QAction *m_actNewTemplate;
    QAction *m_actOpenTemplate;
    QAction *m_actSaveTemplate;
    QAction *m_actSaveAsTemplate;
    QAction *m_actDelTemplate;
    QAction *m_actBindVarSource;
    QAction *m_actUnbindVarSource;

    QToolButton *m_btnImExport;
    QMenu *m_menuImExport;
    QAction *m_actImportTemplate;
    QAction *m_actExportTemplate;
    QAction *m_actImportExcel;
    QAction *m_actExportExcel;

    QToolButton *m_btnCell;
    QMenu *m_menuCell;
    QAction *m_actInsertPic;
    QAction *m_actRemovePic;
    QAction *m_actMergeCell;
    QAction *m_actSplitCell;
    QAction *m_actCellFont;
    QAction *m_actCellColor;
    QAction *m_actCellFrame;
    QAction *m_actCellBindVar;
    QAction *m_actCellUnbindVar;

    QToolButton *m_btnAlign;
    QMenu *m_menuAlign;
    QMenu *m_menuHAlign;
    QMenu *m_menuVAlign;
    QAction *m_actHLeftAlign;
    QAction *m_actHCenterAlign;
    QAction *m_actHRightAlign;
    QAction *m_actVTopAlign;
    QAction *m_actVCenterAlign;
    QAction *m_actVBottomAlign;

    QToolButton *m_btnSysComponent;
    QMenu *m_menuSysComponent;
    QAction *m_actInsertCheckBox;
    QAction *m_actInsertComboBox;
    QAction *m_actInsertSpinBox;
    QAction *m_actInsertDateTimeEdit;

    QToolButton *m_btnSysPic;
    QMenu *m_menuSysPic;
    QAction *m_actSysPic1;
    QAction *m_actSysPic2;
    QAction *m_actSysPic3;


    QToolButton *m_btnVarSourceOp;
    QMenu *m_menuVarSourceOp;
    QAction *m_actOpenVarSource;
    QAction *m_actAddVarSource;
    QAction *m_actDelVarSource;
    QAction *m_actExportVarSourceTemplate;
    QAction *m_actImportVarSource;

    QToolButton *m_tbPrintHtml;
    QToolButton *m_tbPrintPdf;
    QToolButton *m_tbPrint;
    QToolButton *m_tbHelp;

    //right.
    ZTemplateWidget *m_templateWidget;
    QTabWidget* m_tabWidget;


    //main layout.
    QHBoxLayout *m_hLayoutMain;
};
#endif // PTEMPLATEEDITOR_H
