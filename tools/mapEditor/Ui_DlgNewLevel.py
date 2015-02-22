# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file './ui/newlevel.ui'
#
# Created: Sun Feb 22 18:18:08 2015
#      by: PyQt5 UI code generator 5.4
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_DlgNewLevel(object):
    def setupUi(self, DlgNewLevel):
        DlgNewLevel.setObjectName("DlgNewLevel")
        DlgNewLevel.resize(248, 125)
        self.verticalLayoutWidget_2 = QtWidgets.QWidget(DlgNewLevel)
        self.verticalLayoutWidget_2.setGeometry(QtCore.QRect(0, 0, 241, 121))
        self.verticalLayoutWidget_2.setObjectName("verticalLayoutWidget_2")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.verticalLayoutWidget_2)
        self.verticalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.horizontalLayout_5 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_5.setObjectName("horizontalLayout_5")
        self.label = QtWidgets.QLabel(self.verticalLayoutWidget_2)
        self.label.setObjectName("label")
        self.horizontalLayout_5.addWidget(self.label)
        self.leLevelName = QtWidgets.QLineEdit(self.verticalLayoutWidget_2)
        self.leLevelName.setObjectName("leLevelName")
        self.horizontalLayout_5.addWidget(self.leLevelName)
        self.verticalLayout_2.addLayout(self.horizontalLayout_5)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.lblWidth = QtWidgets.QLabel(self.verticalLayoutWidget_2)
        self.lblWidth.setObjectName("lblWidth")
        self.horizontalLayout.addWidget(self.lblWidth)
        self.sboxWidth = QtWidgets.QSpinBox(self.verticalLayoutWidget_2)
        self.sboxWidth.setMinimum(1)
        self.sboxWidth.setMaximum(10)
        self.sboxWidth.setObjectName("sboxWidth")
        self.horizontalLayout.addWidget(self.sboxWidth)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.lblHeight = QtWidgets.QLabel(self.verticalLayoutWidget_2)
        self.lblHeight.setObjectName("lblHeight")
        self.horizontalLayout_2.addWidget(self.lblHeight)
        self.sboxHeight = QtWidgets.QSpinBox(self.verticalLayoutWidget_2)
        self.sboxHeight.setMinimum(1)
        self.sboxHeight.setMaximum(10)
        self.sboxHeight.setObjectName("sboxHeight")
        self.horizontalLayout_2.addWidget(self.sboxHeight)
        self.horizontalLayout.addLayout(self.horizontalLayout_2)
        self.horizontalLayout_3.addLayout(self.horizontalLayout)
        self.verticalLayout_2.addLayout(self.horizontalLayout_3)
        self.buttonBox = QtWidgets.QDialogButtonBox(self.verticalLayoutWidget_2)
        self.buttonBox.setOrientation(QtCore.Qt.Horizontal)
        self.buttonBox.setStandardButtons(QtWidgets.QDialogButtonBox.Cancel|QtWidgets.QDialogButtonBox.Ok)
        self.buttonBox.setCenterButtons(True)
        self.buttonBox.setObjectName("buttonBox")
        self.verticalLayout_2.addWidget(self.buttonBox)

        self.retranslateUi(DlgNewLevel)
        self.buttonBox.accepted.connect(DlgNewLevel.accept)
        self.buttonBox.rejected.connect(DlgNewLevel.reject)
        QtCore.QMetaObject.connectSlotsByName(DlgNewLevel)

    def retranslateUi(self, DlgNewLevel):
        _translate = QtCore.QCoreApplication.translate
        DlgNewLevel.setWindowTitle(_translate("DlgNewLevel", "New Level"))
        self.label.setText(_translate("DlgNewLevel", "Level name"))
        self.lblWidth.setText(_translate("DlgNewLevel", "Width"))
        self.lblHeight.setText(_translate("DlgNewLevel", "Height"))

