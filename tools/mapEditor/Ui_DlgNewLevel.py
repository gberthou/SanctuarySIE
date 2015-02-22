# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file './ui/newlevel.ui'
#
# Created: Sun Feb 22 17:18:30 2015
#      by: PyQt5 UI code generator 5.4
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_DlgNewLevel(object):
    def setupUi(self, DlgNewLevel):
        DlgNewLevel.setObjectName("DlgNewLevel")
        DlgNewLevel.resize(199, 119)
        self.buttonBox = QtWidgets.QDialogButtonBox(DlgNewLevel)
        self.buttonBox.setGeometry(QtCore.QRect(10, 90, 171, 32))
        self.buttonBox.setOrientation(QtCore.Qt.Horizontal)
        self.buttonBox.setStandardButtons(QtWidgets.QDialogButtonBox.Cancel|QtWidgets.QDialogButtonBox.Ok)
        self.buttonBox.setObjectName("buttonBox")
        self.horizontalLayoutWidget_3 = QtWidgets.QWidget(DlgNewLevel)
        self.horizontalLayoutWidget_3.setGeometry(QtCore.QRect(0, 0, 196, 80))
        self.horizontalLayoutWidget_3.setObjectName("horizontalLayoutWidget_3")
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout(self.horizontalLayoutWidget_3)
        self.horizontalLayout_3.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.lblWidth = QtWidgets.QLabel(self.horizontalLayoutWidget_3)
        self.lblWidth.setObjectName("lblWidth")
        self.horizontalLayout.addWidget(self.lblWidth)
        self.sboxWidth = QtWidgets.QSpinBox(self.horizontalLayoutWidget_3)
        self.sboxWidth.setMinimum(1)
        self.sboxWidth.setMaximum(10)
        self.sboxWidth.setObjectName("sboxWidth")
        self.horizontalLayout.addWidget(self.sboxWidth)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.lblHeight = QtWidgets.QLabel(self.horizontalLayoutWidget_3)
        self.lblHeight.setObjectName("lblHeight")
        self.horizontalLayout_2.addWidget(self.lblHeight)
        self.sboxHeight = QtWidgets.QSpinBox(self.horizontalLayoutWidget_3)
        self.sboxHeight.setMinimum(1)
        self.sboxHeight.setMaximum(10)
        self.sboxHeight.setObjectName("sboxHeight")
        self.horizontalLayout_2.addWidget(self.sboxHeight)
        self.horizontalLayout.addLayout(self.horizontalLayout_2)
        self.horizontalLayout_3.addLayout(self.horizontalLayout)

        self.retranslateUi(DlgNewLevel)
        self.buttonBox.accepted.connect(DlgNewLevel.accept)
        self.buttonBox.rejected.connect(DlgNewLevel.reject)
        QtCore.QMetaObject.connectSlotsByName(DlgNewLevel)

    def retranslateUi(self, DlgNewLevel):
        _translate = QtCore.QCoreApplication.translate
        DlgNewLevel.setWindowTitle(_translate("DlgNewLevel", "New Level"))
        self.lblWidth.setText(_translate("DlgNewLevel", "Width"))
        self.lblHeight.setText(_translate("DlgNewLevel", "Height"))

