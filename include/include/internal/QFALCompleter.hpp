#pragma once

// Qt
#include <QCompleter> // Required for inheritance

/**
 * @brief Class, that describes completer with
 * Falcon specific types and functions.
 */
class QFALCompleter : public QCompleter
{
    Q_OBJECT

public:

    /**
     * @brief Constructor.
     * @param parent Pointer to parent QObject.
     */
    explicit QFALCompleter(QObject* parent=nullptr);
};


