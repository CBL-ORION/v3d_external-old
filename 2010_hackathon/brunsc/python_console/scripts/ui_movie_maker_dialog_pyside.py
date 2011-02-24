# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'movie_maker_dialog.ui'
#
# Created: Thu Feb 24 14:38:21 2011
#      by: PySide uic UI code generator
#
# WARNING! All changes made in this file will be lost!

from PySide import QtCore, QtGui

class Ui_movie_dialog(object):
    def setupUi(self, movie_dialog):
        movie_dialog.setObjectName("movie_dialog")
        movie_dialog.resize(529, 361)
        self.verticalLayout_2 = QtGui.QVBoxLayout(movie_dialog)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.horizontalLayout = QtGui.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label_2 = QtGui.QLabel(movie_dialog)
        self.label_2.setWordWrap(True)
        self.label_2.setTextInteractionFlags(QtCore.Qt.LinksAccessibleByMouse|QtCore.Qt.TextSelectableByKeyboard|QtCore.Qt.TextSelectableByMouse)
        self.label_2.setObjectName("label_2")
        self.horizontalLayout.addWidget(self.label_2)
        self.groupBox = QtGui.QGroupBox(movie_dialog)
        self.groupBox.setObjectName("groupBox")
        self.verticalLayout = QtGui.QVBoxLayout(self.groupBox)
        self.verticalLayout.setObjectName("verticalLayout")
        self.addCurrentViewButton = QtGui.QPushButton(self.groupBox)
        self.addCurrentViewButton.setDefault(True)
        self.addCurrentViewButton.setObjectName("addCurrentViewButton")
        self.verticalLayout.addWidget(self.addCurrentViewButton)
        self.horizontalLayout_2 = QtGui.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.label = QtGui.QLabel(self.groupBox)
        self.label.setObjectName("label")
        self.horizontalLayout_2.addWidget(self.label)
        self.frameIntervalLineEdit = QtGui.QLineEdit(self.groupBox)
        self.frameIntervalLineEdit.setMaximumSize(QtCore.QSize(50, 16777215))
        self.frameIntervalLineEdit.setText("2.0")
        self.frameIntervalLineEdit.setMaxLength(6)
        self.frameIntervalLineEdit.setObjectName("frameIntervalLineEdit")
        self.horizontalLayout_2.addWidget(self.frameIntervalLineEdit)
        self.label_3 = QtGui.QLabel(self.groupBox)
        self.label_3.setObjectName("label_3")
        self.horizontalLayout_2.addWidget(self.label_3)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.keyFrameLabel = QtGui.QLabel(self.groupBox)
        self.keyFrameLabel.setObjectName("keyFrameLabel")
        self.verticalLayout.addWidget(self.keyFrameLabel)
        self.deleteAllButton = QtGui.QPushButton(self.groupBox)
        self.deleteAllButton.setObjectName("deleteAllButton")
        self.verticalLayout.addWidget(self.deleteAllButton)
        self.horizontalLayout.addWidget(self.groupBox)
        self.verticalLayout_2.addLayout(self.horizontalLayout)
        self.scrollArea = QtGui.QScrollArea(movie_dialog)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.scrollArea.sizePolicy().hasHeightForWidth())
        self.scrollArea.setSizePolicy(sizePolicy)
        self.scrollArea.setVerticalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOff)
        self.scrollArea.setHorizontalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOn)
        self.scrollArea.setWidgetResizable(True)
        self.scrollArea.setObjectName("scrollArea")
        self.scrollAreaWidgetContents = QtGui.QWidget(self.scrollArea)
        self.scrollAreaWidgetContents.setGeometry(QtCore.QRect(0, 0, 503, 61))
        self.scrollAreaWidgetContents.setObjectName("scrollAreaWidgetContents")
        self.horizontalLayout_3 = QtGui.QHBoxLayout(self.scrollAreaWidgetContents)
        self.horizontalLayout_3.setContentsMargins(0, 5, 0, 5)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        spacerItem = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_3.addItem(spacerItem)
        self.frameCartoonLabel = QtGui.QLabel(self.scrollAreaWidgetContents)
        self.frameCartoonLabel.setMinimumSize(QtCore.QSize(50, 50))
        self.frameCartoonLabel.setMaximumSize(QtCore.QSize(50, 50))
        self.frameCartoonLabel.setFrameShape(QtGui.QFrame.Box)
        self.frameCartoonLabel.setFrameShadow(QtGui.QFrame.Plain)
        self.frameCartoonLabel.setLineWidth(2)
        self.frameCartoonLabel.setObjectName("frameCartoonLabel")
        self.horizontalLayout_3.addWidget(self.frameCartoonLabel)
        spacerItem1 = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_3.addItem(spacerItem1)
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)
        self.verticalLayout_2.addWidget(self.scrollArea)
        self.buttonBox = QtGui.QDialogButtonBox(movie_dialog)
        self.buttonBox.setOrientation(QtCore.Qt.Horizontal)
        self.buttonBox.setStandardButtons(QtGui.QDialogButtonBox.Save)
        self.buttonBox.setObjectName("buttonBox")
        self.verticalLayout_2.addWidget(self.buttonBox)
        self.label.setBuddy(self.frameIntervalLineEdit)
        self.label_3.setBuddy(self.frameIntervalLineEdit)

        self.retranslateUi(movie_dialog)
        QtCore.QObject.connect(self.buttonBox, QtCore.SIGNAL("accepted()"), movie_dialog.accept)
        QtCore.QObject.connect(self.buttonBox, QtCore.SIGNAL("rejected()"), movie_dialog.reject)
        QtCore.QMetaObject.connectSlotsByName(movie_dialog)

    def retranslateUi(self, movie_dialog):
        movie_dialog.setWindowTitle(QtGui.QApplication.translate("movie_dialog", "V3DCinema Movie Maker", None, QtGui.QApplication.UnicodeUTF8))
        self.label_2.setText(QtGui.QApplication.translate("movie_dialog", "Adjust the V3D \'3D View\' to the orientation you want to see in your movie.  Then press \'Add current view\'.  Keep changing the view and pressing \'Add current view\' until you have included all of the key frames of your movie.  \n"
"Press \'Play\' to preview your movie.  \n"
"After you are satisfied with your movie, press \'Save\' to write your movie frames to disk. \n"
"Converting frames to a movie file is an exercise left to the user...", None, QtGui.QApplication.UnicodeUTF8))
        self.groupBox.setTitle(QtGui.QApplication.translate("movie_dialog", "Key Frames", None, QtGui.QApplication.UnicodeUTF8))
        self.addCurrentViewButton.setText(QtGui.QApplication.translate("movie_dialog", "Add current view", None, QtGui.QApplication.UnicodeUTF8))
        self.label.setText(QtGui.QApplication.translate("movie_dialog", "after", None, QtGui.QApplication.UnicodeUTF8))
        self.label_3.setText(QtGui.QApplication.translate("movie_dialog", "seconds.", None, QtGui.QApplication.UnicodeUTF8))
        self.keyFrameLabel.setText(QtGui.QApplication.translate("movie_dialog", "No key frames added", None, QtGui.QApplication.UnicodeUTF8))
        self.deleteAllButton.setText(QtGui.QApplication.translate("movie_dialog", "Delete all frames", None, QtGui.QApplication.UnicodeUTF8))
        self.frameCartoonLabel.setText(QtGui.QApplication.translate("movie_dialog", "Frame", None, QtGui.QApplication.UnicodeUTF8))

