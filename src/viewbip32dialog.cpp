///////////////////////////////////////////////////////////////////////////////
//
// CoinVault
//
// viewbip32dialog.cpp
//
// Copyright (c) 2013 Eric Lombrozo
//
// All Rights Reserved.

#include "viewbip32dialog.h"

#include <stdutils/uchar_vector.h>
#include <CoinCore/Base58Check.h>

#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLabel>

#include <stdexcept>

ViewBIP32Dialog::ViewBIP32Dialog(const secure_bytes_t& extendedKey, QWidget* parent)
    : QDialog(parent)
{
    QLabel* promptLabel = new QLabel(tr("BIP32 Extended Key:"));

    QTextEdit* base58Edit = new QTextEdit();
    base58Edit->setReadOnly(true);
    base58Edit->setText(toBase58Check(extendedKey).c_str());

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->setSizeConstraint(QLayout::SetNoConstraint);
    mainLayout->addWidget(promptLabel);
    mainLayout->addWidget(base58Edit);
    setLayout(mainLayout);

    resize(1000, 100);
}
