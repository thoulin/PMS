#ifndef ZLISTTASKDIA_H
#define ZLISTTASKDIA_H

#include "NetProtocol/pnetframe.h"
#include "BasePart/zbaseinfodia.h"
#include <QToolButton>
class ZListTaskDia : public ZBaseInfoDia
{
public:
    ZListTaskDia(QWidget *parent=0);
    ~ZListTaskDia();
    void ZExecuteListOp(qint32 type);
    void ZParseAckNetFrmXmlData();

private:
    QLabel *m_llMsg;
    QToolButton *m_tbOkay;
    QVBoxLayout *m_vLayout;
};

#endif // ZLISTTASKDIA_H
