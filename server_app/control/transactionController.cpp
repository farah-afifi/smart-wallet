#include "transactionController.h"
#include "repositoriesDB/transactionsRepository.h"

void TransactionController::makeTransaction(int ID, string type, long Amount)
{
    int status = TransactionRepository().InsertTransaction(ID, type, Amount);
    if (status != -1)
        cout << "transaction Added successfully\n";
    else
        cout << "error occured!\n";
}
void TransactionController::getTransactions(TCPStreamInfo *stream, int ID)
{
    vector<Transaction> transactions;
    transactions = TransactionRepository().getTransactions(ID);

    stream->send(to_string(transactions.size()).c_str(), 50);
    if (transactions.size() != 0)
    {
        for (int i = 0; i < transactions.size(); i++)
        {
            stream->send(transactions[i].getType().c_str(), 50);
            stream->send(to_string(transactions[i].getAmount()).c_str(), 500);
            stream->send(transactions[i].getDate().c_str(), 50);
        }
        cout << "transctions fetched!\n";
    }
    else
    {
    }
}
