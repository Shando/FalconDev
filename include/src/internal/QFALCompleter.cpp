// QCodeEditor
#include <../Falcon/include/include/QFALCompleter>
#include <../Falcon/include/include/QLanguage>

// Qt
#include <QStringListModel>
#include <QFile>

QFALCompleter::QFALCompleter(QObject *parent) :
    QCompleter(parent)
{
    // Setting up Falcon types
    QStringList list;

    //Q_INIT_RESOURCE(qcodeeditor_resources);
    QFile fl(":/files/resources/languages/fal.xml");

    if (!fl.open(QIODevice::ReadOnly))
    {
        return;
    }

    QLanguage language(&fl);

    if (!language.isLoaded())
    {
        return;
    }

    auto keys = language.keys();
    for (auto&& key : keys)
    {
        auto names = language.names(key);
        list.append(names);
    }

    setModel(new QStringListModel(list, this));
    setCompletionColumn(0);
    setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    setCaseSensitivity(Qt::CaseSensitive);
    setWrapAround(true);
}
