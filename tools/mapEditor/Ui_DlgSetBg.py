# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file './ui/setbg.ui'
#
# Created: Mon Feb 23 21:55:52 2015
#      by: PyQt5 UI code generator 5.4
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_DlgSetBg(object):
    def setupUi(self, DlgSetBg):
        DlgSetBg.setObjectName("DlgSetBg")
        DlgSetBg.resize(402, 273)
        self.buttonBox = QtWidgets.QDialogButtonBox(DlgSetBg)
        self.buttonBox.setGeometry(QtCore.QRect(10, 240, 381, 32))
        self.buttonBox.setOrientation(QtCore.Qt.Horizontal)
        self.buttonBox.setStandardButtons(QtWidgets.QDialogButtonBox.Cancel|QtWidgets.QDialogButtonBox.Ok)
        self.buttonBox.setObjectName("buttonBox")
        self.verticalLayoutWidget = QtWidgets.QWidget(DlgSetBg)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(5, 9, 391, 221))
        self.verticalLayoutWidget.setObjectName("verticalLayoutWidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout.setObjectName("verticalLayout")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label = QtWidgets.QLabel(self.verticalLayoutWidget)
        self.label.setObjectName("label")
        self.horizontalLayout.addWidget(self.label)
        self.leBg0 = QtWidgets.QLineEdit(self.verticalLayoutWidget)
        self.leBg0.setObjectName("leBg0")
        self.horizontalLayout.addWidget(self.leBg0)
        self.btnBrowse0 = QtWidgets.QPushButton(self.verticalLayoutWidget)
        self.btnBrowse0.setObjectName("btnBrowse0")
        self.horizontalLayout.addWidget(self.btnBrowse0)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.label_2 = QtWidgets.QLabel(self.verticalLayoutWidget)
        self.label_2.setObjectName("label_2")
        self.horizontalLayout_2.addWidget(self.label_2)
        self.leBg1 = QtWidgets.QLineEdit(self.verticalLayoutWidget)
        self.leBg1.setObjectName("leBg1")
        self.horizontalLayout_2.addWidget(self.leBg1)
        self.btnBrowse1 = QtWidgets.QPushButton(self.verticalLayoutWidget)
        self.btnBrowse1.setObjectName("btnBrowse1")
        self.horizontalLayout_2.addWidget(self.btnBrowse1)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.label_3 = QtWidgets.QLabel(self.verticalLayoutWidget)
        self.label_3.setObjectName("label_3")
        self.horizontalLayout_3.addWidget(self.label_3)
        self.leBg2 = QtWidgets.QLineEdit(self.verticalLayoutWidget)
        self.leBg2.setObjectName("leBg2")
        self.horizontalLayout_3.addWidget(self.leBg2)
        self.btnBrowse2 = QtWidgets.QPushButton(self.verticalLayoutWidget)
        self.btnBrowse2.setObjectName("btnBrowse2")
        self.horizontalLayout_3.addWidget(self.btnBrowse2)
        self.verticalLayout.addLayout(self.horizontalLayout_3)
        self.horizontalLayout_4 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.label_4 = QtWidgets.QLabel(self.verticalLayoutWidget)
        self.label_4.setObjectName("label_4")
        self.horizontalLayout_4.addWidget(self.label_4)
        self.leBg3 = QtWidgets.QLineEdit(self.verticalLayoutWidget)
        self.leBg3.setObjectName("leBg3")
        self.horizontalLayout_4.addWidget(self.leBg3)
        self.btnBrowse3 = QtWidgets.QPushButton(self.verticalLayoutWidget)
        self.btnBrowse3.setObjectName("btnBrowse3")
        self.horizontalLayout_4.addWidget(self.btnBrowse3)
        self.verticalLayout.addLayout(self.horizontalLayout_4)

        self.retranslateUi(DlgSetBg)
        self.buttonBox.accepted.connect(DlgSetBg.accept)
        self.buttonBox.rejected.connect(DlgSetBg.reject)
        QtCore.QMetaObject.connectSlotsByName(DlgSetBg)

    def retranslateUi(self, DlgSetBg):
        _translate = QtCore.QCoreApplication.translate
        DlgSetBg.setWindowTitle(_translate("DlgSetBg", "Dialog"))
        self.label.setText(_translate("DlgSetBg", "Background[0]:"))
        self.btnBrowse0.setText(_translate("DlgSetBg", "Browse..."))
        self.label_2.setText(_translate("DlgSetBg", "Background[1]:"))
        self.btnBrowse1.setText(_translate("DlgSetBg", "Browse..."))
        self.label_3.setText(_translate("DlgSetBg", "Background[2]:"))
        self.btnBrowse2.setText(_translate("DlgSetBg", "Browse..."))
        self.label_4.setText(_translate("DlgSetBg", "Background[3]:"))
        self.btnBrowse3.setText(_translate("DlgSetBg", "Browse..."))

