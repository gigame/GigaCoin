#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("gigacoin:GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3?req-dontexist="));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("gigacoin:GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3?dontexist="));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("gigacoin:GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3?label=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3"));
    QVERIFY(rv.label == QString("Wikipedia Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("gigacoin:GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3?amount=0.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("gigacoin:GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3?amount=1.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("gigacoin:GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3?amount=100&label=Wikipedia Example"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Wikipedia Example"));

    uri.setUrl(QString("gigacoin:GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3?message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseBitcoinURI("gigacoin://GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3?message=Wikipedia Example Address", &rv));
    QVERIFY(rv.address == QString("GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("gigacoin:GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3?req-message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("gigacoin:GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3?amount=1,000&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("gigacoin:GLubRapYN45pAV3441wBdfoKPS9tK1Qqv3?amount=1,000.0&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));
}
