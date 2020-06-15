#include "plot.h"

Plot::Plot(QObject *parent,QCustomPlot *Graph,QComboBox *Box) : QObject(parent), graph(Graph), box(Box)
{
    graph ->addGraph();
    graph->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    graph->setInteraction(QCP::iRangeDrag,true);
    graph->setInteraction(QCP::iRangeZoom,true);
    graph->xAxis->setLabel("Time [s]");
    refresh_tim = new QTimer;
    refresh_tim->start(40);
    connect(refresh_tim,SIGNAL(timeout()),this,SLOT(draw()));
    connect(graph,SIGNAL(mouseDoubleClick(QMouseEvent*)),this,SLOT(stop_plotting()));

}

void Plot::set_Ylabel(QString label)
{
    graph->yAxis->setLabel(label);
}

void Plot::set_Xlabel(QString label)
{
    graph->xAxis->setLabel(label);
}

void Plot::draw()
{   QString selected = box->currentText();
    double key=0;
    if(selected=="Yaw"){
        graph->yAxis->setLabel("Yaw angle [rad]");
        graph->graph()->data()->set(PY);
        key = (PY.constEnd()-1)->key;
    }
//    else if(selected=="CPU temp"){
//        graph->yAxis->setLabel("Signal strength [dB]");
//        graph->graph()->data()->set(PCT);
//        key = (PCT.constEnd()-1)->key;
//    }
    else if(selected=="Link quality"){
        graph->yAxis->setLabel("Link quality [dB]");
         graph->graph()->data()->set(PWQ);
         key = (PWQ.constEnd()-1)->key;
    }
    else if(selected=="Signal level"){
        graph->yAxis->setLabel("Signal strength [dB]");
        graph->graph()->data()->set(PWS);
        key = (PWS.constEnd()-1)->key;
    }
//    else if(selected=="CPU usage"){
//        graph->yAxis->setLabel("Signal strength [dB]");
//        graph->graph()->data()->set(PCU);
//        key = (PCU.constEnd()-1)->key;
//    }
    else if(selected=="Battery voltage"){
        graph->yAxis->setLabel("Voltage [V]");
        graph->graph()->data()->set(BV);
        key = (BV.constEnd()-1)->key;
    }
    else if(selected=="Left motor power"){
        graph->yAxis->setLabel("Left motor power [W]");
        graph->graph()->data()->set(LMP);
        key = (LMP.constEnd()-1)->key;
    }
    else if(selected=="Left motor encoder"){
        graph->yAxis->setLabel("Left encoder");
        graph->graph()->data()->set(MLD);
        key = (MLD.constEnd()-1)->key;
    }
    else if(selected=="Right motor power"){
        graph->yAxis->setLabel("Right motor power [W]");
        graph->graph()->data()->set(RMP);
        key = (RMP.constEnd()-1)->key;
    }
    else if(selected=="Right motor encoder"){
        graph->yAxis->setLabel("Left encoder");
        graph->graph()->data()->set(MRD);
        key = (MRD.constEnd()-1)->key;
    }

    graph->xAxis->setRange(key-3,key+3);
    graph->yAxis->rescale(true);
    graph->replot();
    graph->update();
}

void Plot::stop_plotting()
{
    if(refresh_tim->isActive())
        refresh_tim->stop();
    else
        refresh_tim->start();
}

void Plot::add_point(const QString &name,const QCPGraphData &value)
{
    if(name == "LMP")
        LMP.push_back(value);
    else if(name == "RMP")
        RMP.push_back(value);
    else if(name == "MLD")
        MLD.push_back(value);
    else if(name == "MRD")
        MRD.push_back(value);
    else if(name == "PY")
        PY.push_back(value);
    else if(name == "BV")
        BV.push_back(value);
    else if(name == "PWQ")
        PWQ.push_back(value);
    else if(name == "PWS")
        PWS.push_back(value);
//    else if(nazwa == "PCU")
//        PCU.push_back(liczba);
//    else if(nazwa == "PCT")
//        PCT.push_back(liczba);
//    QObject *p = sender();
//    qDebug()  << p->objectName();
//    qDebug() << LMP.size();
//    qDebug() << RMP.size();
}

