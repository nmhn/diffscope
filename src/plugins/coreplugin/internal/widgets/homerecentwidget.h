#ifndef HOMERECENTWIDGET_H
#define HOMERECENTWIDGET_H

#include <QButtonGroup>
#include <QFrame>
#include <QHash>
#include <QLabel>
#include <QLineEdit>
#include <QSplitter>
#include <QVBoxLayout>

#include <QMWidgets/ctabbutton.h>
#include <QMWidgets/qmequalboxlayout.h>
#include <QMWidgets/cbasicframe.h>

#include <SVSCraftWidgets/linearscrollarea.h>
#include <SVSCraftWidgets/titlelistwidget.h>

namespace Core::Internal {

    class HomeRecentTopFrame : public CBasicFrame {
        Q_OBJECT
    public:
        explicit HomeRecentTopFrame(QWidget *parent = nullptr);
        ~HomeRecentTopFrame();

    public:
        void reloadStrings();

        void addButton(QAbstractButton *btn);
        void removeButton(QAbstractButton *btn);

    Q_SIGNALS:
        void textChanged(const QString &text);

    protected:
        QLineEdit *searchBox;
        QMEqualBoxLayout *topLayout;
    };

    class HomeRecentBottomFrame : public CBasicFrame {
        Q_OBJECT
    public:
        explicit HomeRecentBottomFrame(QWidget *parent = nullptr);
        ~HomeRecentBottomFrame();

    public:
        void reloadStrings();
        void reloadRecentFiles();

        void setFilterKeyword(const QString &keyword);

    Q_SIGNALS:
        void openFileRequested(const QString &fileName);

    protected:
        QVBoxLayout *bottomLayout;
        SVS::TitleListWidget *fileWidget;
        QLabel *emptyLabel;

        QString m_keyword;

        void updateListFilter();
        void updateEmptyLabel();

    private:
        void _q_recentFilesChanged();
        void _q_itemClickedEx(const QModelIndex &index, int button);
    };

    class HomeRecentWidget : public QSplitter {
        Q_OBJECT
    public:
        explicit HomeRecentWidget(QWidget *parent = nullptr);
        ~HomeRecentWidget();

        void reloadStrings();

        HomeRecentTopFrame *topWidget;
        HomeRecentBottomFrame *bottomWidget;

    private:
        void _q_searchTextChanged(const QString &text);
    };

}

#endif // HOMERECENTWIDGET_H
