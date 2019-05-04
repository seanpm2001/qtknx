/******************************************************************************
**
** Copyright (C) 2019 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtKnx module.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
******************************************************************************/

#include "manufacturers.h"

#include <QtCore/qvector.h>

QT_BEGIN_NAMESPACE

struct Manufacturer
{
    Manufacturer() = default;
    Manufacturer(int i, const char *mId, const char *n)
        : id(i)
        , manufacturerId(mId)
        , name(QString::fromUtf8(QByteArray::fromHex(n)))
    {}

    int id;
    QLatin1String manufacturerId;
    QString name;

    static const QVector<Manufacturer> &manufacturers()
    {
        static QVector<Manufacturer> sManufacturers {
            { 1, "M-0001", "5369656d656e73" },
            { 2, "M-0002", "414242" },
            { 4, "M-0004", "416c627265636874204a756e67" },
            { 5, "M-0005", "42746963696e6f" },
            { 6, "M-0006", "4265726b6572" },
            { 7, "M-0007", "42757363682d4a616567657220456c656b74726f" },
            { 11, "M-000B", "4c454752414e4420417070617265696c6c61676520c3a96c6563747269717565" },
            { 12, "M-000C", "4d657274656e" },
            { 14, "M-000E", "4142425370412d53414345204469766973696f6e" },
            { 22, "M-0016", "536965646c6520262053c3b6686e65" },
            { 24, "M-0018", "456265726c65" },
            { 25, "M-0019", "474557495353" },
            { 27, "M-001B", "416c626572742041636b65726d616e6e" },
            { 28, "M-001C", "53636875706120476d6248" },
            { 29, "M-001D", "414242205343485745495a" },
            { 30, "M-001E", "46656c6c6572" },
            { 32, "M-0020", "4445484e20262053c396484e45" },
            { 33, "M-0021", "4352414254524545" },
            { 36, "M-0024", "5061756c20486f63686bc3b670706572" },
            { 37, "M-0025", "416c74656e62757267657220456c656374726f6e6963" },
            { 41, "M-0029", "4772c3a473736c696e" },
            { 42, "M-002A", "53696d6f6e" },
            { 44, "M-002C", "56494d4152" },
            { 45, "M-002D", "4d6f656c6c657220476562c3a47564656175746f6d6174696f6e204b47" },
            { 46, "M-002E", "456c74616b6f" },
            { 49, "M-0031", "426f7363682d5369656d656e73204861757368616c7473676572c3a47465" },
            { 52, "M-0034", "524954544f20476d624826436f2e4b47" },
            { 53, "M-0035", "506f77657220436f6e74726f6c73" },
            { 55, "M-0037", "5a554d544f42454c" },
            { 57, "M-0039", "50686f656e697820436f6e74616374" },
            { 61, "M-003D", "5741474f204b6f6e74616b74746563686e696b" },
            { 66, "M-0042", "5769656c616e6420456c656374726963" },
            { 67, "M-0043", "4865726d616e6e204b6c65696e68756973" },
            { 69, "M-0045", "5374696562656c20456c74726f6e" },
            { 71, "M-0047", "546568616c6974" },
            { 72, "M-0048", "54686562656e204147" },
            { 73, "M-0049", "57696c68656c6d20527574656e6265636b" },
            { 75, "M-004B", "57696e6b68617573" },
            { 76, "M-004C", "526f6265727420426f736368" },
            { 78, "M-004E", "536f6d6679" },
            { 80, "M-0050", "576f6572747a" },
            { 81, "M-0051", "56696573736d616e6e205765726b65" },
            { 82, "M-0052", "494d4920487964726f6e696320456e67696e656572696e67" },
            { 83, "M-0053", "4a6f682e205661696c6c616e74" },
            { 85, "M-0055", "414d5020446575747363686c616e64" },
            { 89, "M-0059", "426f73636820546865726d6f746563686e696b20476d6248" },
            { 90, "M-005A", "534546202d2045434f544543" },
            { 92, "M-005C", "444f524d4120476d6248202b20436f2e204b47" },
            { 93, "M-005D", "57696e646f774d617374657220412f53" },
            { 94, "M-005E", "57616c74686572205765726b65" },
            { 95, "M-005F", "4f524153" },
            { 97, "M-0061", "44c3a47477796c6572" },
            { 98, "M-0062", "456c65637472616b" },
            { 99, "M-0063", "54656368656d" },
            { 100, "M-0064", "5363686e656964657220456c65637472696320496e647573747269657320534153" },
            { 101, "M-0065", "5748442057696c68656c6d204875626572202b2053c3b6686e65" },
            { 102, "M-0066", "42697363686f666620456c656b74726f6e696b" },
            { 104, "M-0068", "4a4550415a" },
            { 105, "M-0069", "525453204175746f6d6174696f6e" },
            { 106, "M-006A", "4549424d41524b5420476d6248" },
            { 107, "M-006B", "574152454d412052656e6b686f6666205345" },
            { 108, "M-006C", "45656c656374726f6e" },
            { 109, "M-006D", "42656c64656e20576972652026204361626c6520422e562e" },
            { 110, "M-006E", "4265636b65722d416e74726965626520476d6248" },
            { 111, "M-006F", "4a2e537465686c652b53c3b6686e6520476d6248" },
            { 112, "M-0070", "414746454f" },
            { 113, "M-0071", "5a656e6e696f" },
            { 114, "M-0072", "5441504b4f20546563686e6f6c6f67696573" },
            { 115, "M-0073", "48444c" },
            { 116, "M-0074", "55706f6e6f72" },
            { 117, "M-0075", "7365204c696768746d616e6167656d656e74204147" },
            { 118, "M-0076", "41726375732d656473" },
            { 119, "M-0077", "496e7465736973" },
            { 120, "M-0078", "486572686f6c647420436f6e74726f6c732073726c" },
            { 121, "M-0079", "4e696b6f2d5a75626c696e" },
            { 122, "M-007A", "44757261626c6520546563686e6f6c6f67696573" },
            { 123, "M-007B", "496e6e6f7465616d" },
            { 124, "M-007C", "69736520476d6248" },
            { 125, "M-007D", "5445414d20464f522054524f4e494353" },
            { 126, "M-007E", "43494154" },
            { 127, "M-007F", "52656d656861204256" },
            { 128, "M-0080", "4553594c5558" },
            { 129, "M-0081", "424153414c5445" },
            { 130, "M-0082", "56657374616d61746963" },
            { 131, "M-0083", "4d445420746563686e6f6c6f67696573" },
            { 132, "M-0084", "576172656e646f72666572204bc3bc6368656e20476d6248" },
            { 133, "M-0085", "566964656f2d53746172" },
            { 134, "M-0086", "536974656b" },
            { 135, "M-0087", "434f4e54524f4c74726f6e6963" },
            { 136, "M-0088", "66756e6374696f6e20546563686e6f6c6f6779" },
            { 137, "M-0089", "414d58" },
            { 138, "M-008A", "454c444154" },
            { 139, "M-008B", "50616e61736f6e6963" },
            { 140, "M-008C", "50756c736520546563686e6f6c6f67696573" },
            { 141, "M-008D", "4372657374726f6e" },
            { 142, "M-008E", "535445494e454c2070726f66657373696f6e616c" },
            { 143, "M-008F", "42494c544f4e204c4544204c69676874696e67" },
            { 144, "M-0090", "64656e726f204147" },
            { 145, "M-0091", "476550726f" },
            { 146, "M-0092", "707265757373656e206175746f6d6174696f6e" },
            { 147, "M-0093", "5a6f7070617320496e6475737472696573" },
            { 148, "M-0094", "4d414354454348" },
            { 149, "M-0095", "544543484e4f2d5452454e44" },
            { 150, "M-0096", "4653204361626c6573" },
            { 151, "M-0097", "44656c746120446f7265" },
            { 152, "M-0098", "456973736f756e64" },
            { 153, "M-0099", "436973636f" },
            { 154, "M-009A", "44696e7579" },
            { 155, "M-009B", "694b4e6958" },
            { 156, "M-009C", "526164656d616368657220476572c3a474652d456c656b74726f6e696b20476d6248" },
            { 157, "M-009D", "45476920456c656374726f61637573746963612047656e6572616c2049626572696361" },
            { 158, "M-009E", "42657320e2809320496e67656e69756d" },
            { 159, "M-009F", "456c61624e4554" },
            { 160, "M-00A0", "426c756d6f746978" },
            { 161, "M-00A1", "48756e74657220446f75676c6173" },
            { 162, "M-00A2", "4150524943554d" },
            { 163, "M-00A3", "5449414e5355204175746f6d6174696f6e" },
            { 164, "M-00A4", "427562656e646f726666" },
            { 165, "M-00A5", "4d425320476d6248" },
            { 166, "M-00A6", "456e65727465782042617965726e20476d6248" },
            { 167, "M-00A7", "424d53" },
            { 168, "M-00A8", "53696e61707369" },
            { 169, "M-00A9", "456d6265646465642053797374656d7320534941" },
            { 170, "M-00AA", "4b4e5831" },
            { 171, "M-00AB", "546f6b6b61" },
            { 172, "M-00AC", "4e616e6f53656e7365" },
            { 173, "M-00AD", "50454152204175746f6d6174696f6e20476d6248" },
            { 174, "M-00AE", "444741" },
            { 175, "M-00AF", "4c7574726f6e" },
            { 176, "M-00B0", "4149525a4f4e4520e2809320414c545241" },
            { 177, "M-00B1", "4c6974686f73732044657369676e205377697463686573" },
            { 178, "M-00B2", "334154454c" },
            { 179, "M-00B3", "5068696c69707320436f6e74726f6c73" },
            { 180, "M-00B4", "56454c555820412f53" },
            { 181, "M-00B5", "4c4f59544543" },
            { 182, "M-00B6", "53425320532e702e412e" },
            { 183, "M-00B7", "5349524c414e20546563686e6f6c6f67696573" },
            { 184, "M-00B8", "426c657520436f6d6d2720417a7572" },
            { 185, "M-00B9", "495420476d6248" },
            { 186, "M-00BA", "52454e534f4e" },
            { 187, "M-00BB", "4845502047726f7570" },
            { 188, "M-00BC", "42616c6d617274" },
            { 189, "M-00BD", "47465320476d6248" },
            { 190, "M-00BE", "536368656e6b65722053746f72656e204147" },
            { 191, "M-00BF", "416c676f64756520456c657474726f6e69636120532e722e4c2e" },
            { 192, "M-00C0", "4e6577726f6e2053797374656d" },
            { 193, "M-00C1", "6d61696e74726f6e6963" },
            { 194, "M-00C2", "56616e74616765" },
            { 195, "M-00C3", "466f7265736973" },
            { 196, "M-00C4", "526573656172636820262050726f64756374696f6e204173736f63696174696f6e2053454d" },
            { 197, "M-00C5", "5765696e7a6965726c20456e67696e656572696e6720476d6248" },
            { 198, "M-00C6", "4dc3b6686c656e686f66662057c3a4726d65746563686e696b20476d6248" },
            { 199, "M-00C7", "504b432d47524f5550204f796a" },
            { 200, "M-00C8", "422e452e472e" },
            { 201, "M-00C9", "456c736e657220456c656b74726f6e696b20476d6248" },
            { 202, "M-00CA", "5369656d656e73204275696c64696e6720546563686e6f6c6f676965732028484b2f4368696e6129204c74642e" },
            { 204, "M-00CC", "457574726163" },
            { 205, "M-00CD", "4775737461762048656e73656c20476d6248202620436f2e204b47" },
            { 206, "M-00CE", "4741524f204142" },
            { 207, "M-00CF", "57616c646d616e6e204c69636874746563686e696b" },
            { 208, "M-00D0", "534348c39c434f" },
            { 209, "M-00D1", "454d55" },
            { 210, "M-00D2", "4a4e65742053797374656d73204147" },
            { 214, "M-00D6", "4f2e592e4c2e20456c656374726f6e696373" },
            { 215, "M-00D7", "47616c61782053797374656d" },
            { 216, "M-00D8", "4469736368" },
            { 217, "M-00D9", "4175636f7465616d" },
            { 218, "M-00DA", "4c75786d61746520436f6e74726f6c73" },
            { 219, "M-00DB", "44616e666f7373" },
            { 220, "M-00DC", "41535420476d6248" },
            { 222, "M-00DE", "57494c41204c6575636874656e" },
            { 223, "M-00DF", "622b62204175746f6d6174696f6e732d20756e6420537465756572756e6773746563686e696b" },
            { 225, "M-00E1", "4c696e67672026204a616e6b65" },
            { 227, "M-00E3", "536175746572" },
            { 228, "M-00E4", "53494d55" },
            { 232, "M-00E8", "54686562656e20485453204147" },
            { 233, "M-00E9", "416d616e6e20476d6248" },
            { 234, "M-00EA", "4245524720456e65726769656b6f6e74726f6c6c73797374656d6520476d6248" },
            { 235, "M-00EB", "48c3bc70706520466f726d20536f6e6e656e73636875747a73797374656d6520476d6248" },
            { 237, "M-00ED", "4f76656e74726f70204b47" },
            { 238, "M-00EE", "4772696573736572204147" },
            { 239, "M-00EF", "4950415320476d6248" },
            { 240, "M-00F0", "656c65726f20476d6248" },
            { 241, "M-00F1", "417264616e2050726f64756374696f6e20616e6420496e647573747269616c20436f6e74726f6c73204c74642e" },
            { 242, "M-00F2", "4d65746563204d65c39f746563686e696b20476d6248" },
            { 244, "M-00F4", "454c4b412d456c656b74726f6e696b20476d6248" },
            { 245, "M-00F5", "454c454b54524f414e4c4147454e20442e204e4147454c" },
            { 246, "M-00F6", "547269646f6e696320426175656c656d656e746520476d6248" },
            { 248, "M-00F8", "5374656e676c657220476573656c6c736368616674" },
            { 249, "M-00F9", "5363686e656964657220456c65637472696320284d4729" },
            { 250, "M-00FA", "4b4e58204173736f63696174696f6e" },
            { 251, "M-00FB", "5649564f" },
            { 252, "M-00FC", "4875676f204dc3bc6c6c657220476d6248202620436f204b47" },
            { 253, "M-00FD", "5369656d656e732048564143" },
            { 254, "M-00FE", "415054" },
            { 256, "M-0100", "48696768446f6d" },
            { 257, "M-0101", "546f70205365727669636573" },
            { 258, "M-0102", "616d6269486f6d65" },
            { 259, "M-0103", "444154454320656c656374726f6e6963204147" },
            { 260, "M-0104", "414255532053656375726974792d43656e746572" },
            { 261, "M-0105", "4c6974652d5075746572" },
            { 262, "M-0106", "54616e74726f6e20456c656374726f6e6963" },
            { 263, "M-0107", "59c3b66e6e6574" },
            { 264, "M-0108", "444b582054656368" },
            { 265, "M-0109", "56696174726f6e" },
            { 266, "M-010A", "4e61757469627573" },
            { 267, "M-010B", "4f4e2053656d69636f6e647563746f72" },
            { 268, "M-010C", "4c6f6e67636875616e67" },
            { 269, "M-010D", "4169722d4f6e204147" },
            { 270, "M-010E", "69622d636f6d70616e7920476d6248" },
            { 271, "M-010F", "536174696f6e20466163746f7279" },
            { 272, "M-0110", "4167656e74696c6f20476d6248" },
            { 273, "M-0111", "4d616b656c20456c656b7472696b" },
            { 274, "M-0112", "48656c696f732056656e74696c61746f72656e" },
            { 275, "M-0113", "4f74746f20536f6c7574696f6e7320507465204c7464" },
            { 276, "M-0114", "4169726d6173746572" },
            { 277, "M-0115", "56616c6c6f7820476d6248" },
            { 278, "M-0116", "44616c6974656b" },
            { 279, "M-0117", "4153494e" },
            { 280, "M-0118", "4272696467657320496e74656c6c6967656e636520546563686e6f6c6f677920496e632e" },
            { 281, "M-0119", "4152424f4e4941" },
            { 282, "M-011A", "4b45524d49" },
            { 283, "M-011B", "50524f4c5558" },
            { 284, "M-011C", "436c6963486f6d65" },
            { 285, "M-011D", "434f4d4d4158" },
            { 286, "M-011E", "454145" },
            { 287, "M-011F", "54656e7365" },
            { 288, "M-0120", "5365796f756e6720456c656374726f6e696373" },
            { 289, "M-0121", "4c696665646f6d7573" },
            { 290, "M-0122", "4555524f74726f6e696320546563686e6f6c6f677920476d6248" },
            { 291, "M-0123", "746369" },
            { 292, "M-0124", "52697368756e20456c656374726f6e6963" },
            { 293, "M-0125", "5a697061746f" },
            { 294, "M-0126", "636d2d736563757269747920476d6248202620436f204b47" },
            { 295, "M-0127", "51696e67204361626c6573" },
            { 296, "M-0128", "4c4142494f" },
            { 297, "M-0129", "436f73746572205465636e6f6c6f67696520456c657474726f6e6963686520532e702e412e" },
            { 298, "M-012A", "452e472e45" },
            { 299, "M-012B", "4e4554784175746f6d6174696f6e" },
            { 300, "M-012C", "746563616c6f72" },
            { 301, "M-012D", "55726d657420456c656374726f6e69637320284875697a686f7529204c74642e" },
            { 302, "M-012E", "50656979696e67204275696c64696e6720436f6e74726f6c" },
            { 303, "M-012F", "42505420532e702e412e206120536f63696f20556e69636f" },
            { 304, "M-0130", "4b616e6f6e746563202d204b616e6f6e425553" },
            { 305, "M-0131", "495345522054656368" },
            { 306, "M-0132", "46696e656c696e65" },
            { 307, "M-0133", "435020456c656374726f6e696373204c7464" },
            { 308, "M-0134", "4e696b6f2d536572766f64616e20412f53" },
            { 309, "M-0135", "53696d6f6e" },
            { 310, "M-0136", "474d206d6f64756c6172207076742e204c74642e" },
            { 311, "M-0137", "4655204348454e4720496e74656c6c6967656e6365" },
            { 312, "M-0138", "4e65784b6f6e" },
            { 313, "M-0139", "4645454c20732e722e6c" },
            { 314, "M-013A", "4e6f742041737369676e6564" },
            { 315, "M-013B", "5368656e7a68656e2046616e6861692053616e6a69616e6720456c656374726f6e69637320436f2e2c204c74642e" },
            { 316, "M-013C", "4a69757a686f752047726565626c65" },
            { 317, "M-013D", "41756dc3bc6c6c65722041756d6174696320476d6248" },
            { 318, "M-013E", "45746d616e20456c656374726963" },
            { 319, "M-013F", "454d5420436f6e74726f6c73" },
            { 320, "M-0140", "5a69646154656368204147" },
            { 321, "M-0141", "494447532062766261" },
            { 322, "M-0142", "64616b616e696d6f" },
            { 323, "M-0143", "547265626f72204175746f6d6174696f6e204142" },
            { 324, "M-0144", "536174656c2073702e207a206f2e6f2e" },
            { 325, "M-0145", "527573736f756e642c20496e632e" },
            { 326, "M-0146", "4d696465612048656174696e6720262056656e74696c6174696e672045717569706d656e7420434f204c5444" },
            { 327, "M-0147", "436f6e736f727a696f2054657272616e756f7661" },
            { 328, "M-0148", "576f6c66204865697a746563686e696b20476d6248" },
            { 329, "M-0149", "534f4e544543" },
            { 330, "M-014A", "42656c636f6d204361626c6573204c74642e" },
            { 331, "M-014B", "4775616e677a686f752053656157696e20456c656374726963616c20546563686e6f6c6f6769657320436f2e2c204c74642e" },
            { 332, "M-014C", "416372656c" },
            { 333, "M-014D", "4672616e6b652041717561726f7474657220476d6248" },
            { 334, "M-014E", "4f72696f6e2053797374656d73" },
            { 335, "M-014F", "5363687261636b20546563686e696b20476d6248" },
            { 336, "M-0150", "494e5350524944" },
            { 337, "M-0151", "53756e726963686572" },
            { 338, "M-0152", "4d656e726564206175746f6d6174696f6e2073797374656d287368616e676861692920436f2e2c4c74642e" },
            { 339, "M-0153", "4175726578" },
            { 340, "M-0154", "4a6f736566204261727468656c6d6520476d6248202620436f2e204b47" },
            { 341, "M-0155", "417263686974656374757265204e756d657269717565" },
            { 342, "M-0156", "55502047524f5550" },
            { 343, "M-0157", "54656b6e6f732d4176696e6e6f" },
            { 344, "M-0158", "4e696e67626f20446f6f7961204d656368616e6963202620456c656374726f6e696320546563686e6f6c6f6779" },
            { 345, "M-0159", "546865726d6f6b6f6e2053656e736f72746563686e696b20476d6248" },
            { 346, "M-015A", "42454c494d4f204175746f6d6174696f6e204147" },
            { 347, "M-015B", "5a65686e6465722047726f757020496e7465726e6174696f6e616c204147" },
            { 348, "M-015C", "736b73204b696e6b656c20456c656b74726f6e696b" },
            { 349, "M-015D", "454345205775726d69747a657220476d6248" },
            { 350, "M-015E", "4c415253" },
            { 351, "M-015F", "555243" },
            { 352, "M-0160", "4c69676874436f6e74726f6c" },
            { 353, "M-0161", "5368656e5a68656e20594d" },
            { 354, "M-0162", "4d45414e2057454c4c20456e74657270726973657320436f2e204c74642e" },
            { 355, "M-0163", "4f536978" },
            { 356, "M-0164", "415950524f20546563686e6f6c6f6779" },
            { 357, "M-0165", "48656665692045636f6c69746520536f667477617265" },
            { 358, "M-0166", "456e6e6f" },
            { 359, "M-0167", "4f484f53555245" },
            { 360, "M-0168", "47617265666f776c" },
            { 361, "M-0169", "47455a45" },
            { 362, "M-016A", "4c4720456c656374726f6e69637320496e632e" },
            { 363, "M-016B", "534d4320696e746572696f7273" },
            { 364, "M-016C", "4e6f742041737369676e6564" },
            { 365, "M-016D", "534353204361626c65" },
            { 366, "M-016E", "486f76616c" },
            { 367, "M-016F", "43414e5354" },
            { 368, "M-0170", "48616e675a686f75204265726c696e" },
            { 369, "M-0171", "45564e2d4c69636874746563686e696b" },
            { 370, "M-0172", "7275746563" },
            { 371, "M-0173", "46696e646572" },
            { 372, "M-0174", "46756a697473752047656e6572616c204c696d69746564" },
            { 373, "M-0175", "5a462046726965647269636873686166656e204147" },
            { 374, "M-0176", "437265616c6564" },
            { 375, "M-0177", "4d696c6573204d61676963204175746f6d6174696f6e2050726976617465204c696d69746564" },
            { 376, "M-0178", "452b" },
            { 377, "M-0179", "4974616c636f6e64" },
            { 378, "M-017A", "534154494f4e" },
            { 379, "M-017B", "4e657742657374" },
            { 380, "M-017C", "474453204449474954414c2053595354454d53" },
            { 381, "M-017D", "49646465726f" },
            { 382, "M-017E", "4d424e4c4544" },
            { 383, "M-017F", "56495452554d" },
            { 384, "M-0180", "656b65792062696f6d65747269632073797374656d7320476d6248" },
            { 385, "M-0181", "414d43" },
            { 386, "M-0182", "5452494c555820476d6248202620436f2e204b47" },
            { 387, "M-0183", "5745786365646f" },
            { 388, "M-0184", "56454d455220535041" },
            { 389, "M-0185", "416c6578616e6465722042c3bc726b6c6520476d6248202620436f204b47" },
            { 390, "M-0186", "53656574726f6c6c" },
            { 391, "M-0187", "5368656e7a68656e2048654775616e67" },
            { 392, "M-0188", "4e6f742041737369676e6564" },
            { 393, "M-0189", "5452414e4520422e562e422e41" },
            { 394, "M-018A", "434152454c" },
            { 395, "M-018B", "50726f6c69746520436f6e74726f6c73" },
            { 396, "M-018C", "424f534d4552" },
            { 397, "M-018D", "45554348495053" },
            { 398, "M-018E", "636f6e6e65637420285468696e6b6120636f6e6e65637429" },
            { 399, "M-018F", "5045414b6e78206120444f47415749535420636f6d70616e7920" },
            { 400, "M-0190", "4143454d41544943" },
            { 401, "M-0191", "454c4155535953" },
            { 402, "M-0192", "49544b20456e67696e656572696e67204147" },
            { 403, "M-0193", "417175616d6574726f204147" },
            { 404, "M-0194", "464d5320486f73706974616c69747920507465204c7464" },
            { 405, "M-0195", "4e75766f" },
            { 406, "M-0196", "753a3a4c757820476d6248" },
            { 407, "M-0197", "4272756d62657267204c6575636874656e" },
            { 408, "M-0198", "4c696d65" },
            { 409, "M-0199", "477265617420456d7069726520496e7465726e6174696f6e616c2047726f757020436f2e2c204c74642e" },
            { 410, "M-019A", "4b61766f736870697368726f2041736961" },
            { 411, "M-019B", "563220537041" },
            { 412, "M-019C", "4a6f686e736f6e20436f6e74726f6c73" },
            { 413, "M-019D", "41726b7564" },
            { 414, "M-019E", "4972696469756d204c74642e" },
            { 415, "M-019F", "62736d617274" },
            { 416, "M-01A0", "42414220544543484e4f4c4f47494520476d6248" },
            { 417, "M-01A1", "4e49434520537061" },
            { 418, "M-01A2", "526564666973682047726f757020507479204c7464" },
            { 419, "M-01A3", "53414249414e4120737061" },
            { 420, "M-01A4", "5562656520496e746572616374697665204575726f7065" },
            { 421, "M-01A5", "526578656c" },
            { 422, "M-01A6", "4765732054656b6e696b20412e532e" },
            { 423, "M-01A7", "41766520532e702e412e20" },
            { 424, "M-01A8", "5a6875686169204c7465636820546563686e6f6c6f677920436f2e2c204c74642e20" },
            { 425, "M-01A9", "4152434f4d" },
            { 426, "M-01AA", "56494120546563686e6f6c6f676965732c20496e632e" },
            { 427, "M-01AB", "4645454c534d4152542e" },
            { 428, "M-01AC", "535550434f4e" },
            { 429, "M-01AD", "4d414e4943" },
            { 430, "M-01AE", "5472c3a4756d20646575747363686520456c656b74726f6e696b20476d6248" },
            { 431, "M-01AF", "4e616e6a696e672053687566616e20496e666f726d6174696f6e20746563686e6f6c6f677920436f2e2c4c74642e" },
            { 432, "M-01B0", "455754656368" },
            { 433, "M-01B1", "4b6c75676572204175746f6d6174696f6e20476d6248" },
            { 434, "M-01B2", "4a6f6f6e67416e6720436f6e74726f6c" },
            { 435, "M-01B3", "477265656e436f6e74726f6c7320546563686e6f6c6f67792053646e2e204268642e" },
            { 436, "M-01B4", "494d4520532e702e612e" },
            { 437, "M-01B5", "5369436875616e2048616f44696e67" }
        };
        return sManufacturers;
    }
};

/*!
    \since 5.13
    \inmodule QtKnx
    \namespace QKnx::Ets

    \brief Contains miscellaneous and ETS specific identifiers used throughout the QtKnx library.
*/

/*!
    \since 5.13
    \inmodule QtKnx
    \namespace QKnx::Ets::Manufacturers

    \brief Contains KNX manufacturer-specific identifiers used throughout the QtKnx library.
*/

/*!
    \since 5.13

    Returns the name of a KNX manufacturer for the given manufacturer ID
    \a id or the given default value \a defaultValue if the \c id was not
    found in the list of known manufacturers.
*/
QString QKnx::Ets::Manufacturers::fromId(int id, const QString &defaultValue)
{
    const auto m = Manufacturer::manufacturers();
    const auto it = std::lower_bound(m.constBegin(), m.constEnd(), id,
        [](const Manufacturer &mf, int id) {
            return mf.id < id;
    });
    if (it != m.constEnd())
        return it->name;
    return defaultValue;
}

/*!
    \since 5.13

    Returns the name of a KNX manufacturer for the given manufacturer ID
    \a id or the given default value \a defaultValue if the \c id was not
    found in the list of known manufacturers.

    \note: The \c id must be in the format of \b {M-\\d{4}}.
*/
QString QKnx::Ets::Manufacturers::fromId(const QString &id, const QString &defaultValue)
{
    const auto m = Manufacturer::manufacturers();
    const auto it = std::lower_bound(m.constBegin(), m.constEnd(), id,
        [](const Manufacturer &mf, const QString &id) {
            return mf.id < id;
    });
    if (it != m.constEnd())
        return it->name;
    return defaultValue;
}

QT_END_NAMESPACE
