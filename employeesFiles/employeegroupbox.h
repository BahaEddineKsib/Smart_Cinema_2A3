#ifndef EMPLOYEEGROUPBOX_H
#define EMPLOYEEGROUPBOX_H

#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QLineEdit>

class EmployeeGroupBox : public QWidget
{
    Q_OBJECT
public:
    explicit EmployeeGroupBox(QWidget *parent = nullptr);
    QGroupBox *EmployesBox;
    QPushButton *EmployeeUpdateButton;
    QPushButton *EmployeeDeleteButton;
    QPushButton *EmployeePhotoButtonEdit;
    QLineEdit *EmployeeNameEdit;
    QLabel *EmployeeNameTitle;
    QLineEdit *EmployeeEmailEdit;
    QLabel *EmployeeContactTitle;
    QLabel *EmployeeUsernameTitle;
    QLineEdit *EmployeeUsernameEdit;
    QLabel *EmployeePasswordTitle;
    QLineEdit *EmployeePasswordEdit;
    QComboBox *EmployeeAccessCombo;
    QLabel *EmployeeIdTitle;
    QLabel *EmployeeId;
public slots:
    void UpdateEmployeeSlot();
    void DeleteEmployeeSlot();

signals:

};

#endif // EMPLOYEEGROUPBOX_H
