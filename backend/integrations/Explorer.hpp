/**
 * Filename: Explorer.hpp
 *
 * XCITE is a secure platform utilizing the XTRABYTES Proof of Signature
 * blockchain protocol to host decentralized applications
 *
 * Copyright (c) 2017-2018 Zoltan Szabo & XTRABYTES developers
 *
 * This file is part of an XTRABYTES Ltd. project.
 *
 */

#ifndef EXPLORER_HPP
#define EXPLORER_HPP

#include <QObject>
#include <QtNetwork/QHostInfo>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class Explorer : public QObject
{
    Q_OBJECT
public:
    explicit Explorer(QObject *parent = nullptr);
    QString  getBalanceAddress(QString coin, QString address, QString page);
    QString getTransactionDetails(QString coin, QString transaction);

signals:
    void updateBalance(const QString &coin, const QString &address, const QString &balance);
    void updateTransactions(const QString &transactions, const QString &totalPages);
    void updateTransactionsDetails(const QString &timestamp, const QString &confirmations, const QString &balance, const QString &inputs, const QString &outputs);

public slots:
    void getBalanceEntireWallet(QString);
    void getTransactionList(QString, QString, QString);
    void getDetails(QString, QString);
    void onResult(QNetworkReply *reply);

private:
    QString explorerValue;
};

#endif // EXPLORER_HPP
