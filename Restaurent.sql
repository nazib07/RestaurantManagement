SQLite format 3   @    ;            �                                                ; -�)   �    ��+�                                                                                                                                                 ��WW�}tablesqlitebrowser_�/
++�tableTempTransactionTempTransactionCREATE TABLE `TempTransaction` (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT,
	`item`	TEXT,
	`amount`	INTEGER,
	`order_id`	TEXT UNIQUE
)=Q+ indexsqlite_autoindex_TempTransaction_1TempTransaction   3G! indexsqlite_autoindex_Catagories_1Catagories�!!!�tableCatagoriesCatagoriesCREATE TABLE "Catagories" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT,
	`name`	TEXT UNIQUE,
	`picture`	TEXT,
	`description`	TEXT
)   �/	�=tableFoodsFoodsCREATE TABLE "Foods" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT,
	`Name`	TEXT,
	`Catagory`	INTEGER,
	`Price`	REAL,
	`Picture`	TEXT,
	`Description`	TEXT
)P++Ytablesqlite_sequencesqlite_sequenceCREATE TABLE sqlite_sequence   Q   	� � I��                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       R {salamasdfasdD:/Qt Projects/RestaurantManagement/BoyPhotos/salam.jpg145646543U {#kayasModonpurD:/Qt Projects/RestaurantManagement/BoyPhotos/kayas.jpg15456431313   �'nazibuO {nazibdhakD:/Qt Projects/RestaurantManagement/BoyPhotos/nazib.jpg014563141   � ������                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       6sqlitebrowser_rename_column_ne/	vat	.Users,3TransactionsDetails �9TempTransactionDetails �	Foods!CatagoriesF 	� ��k�L���                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           " %SemaiDesrtVdefalult.jpgNone$ %PuddingDesrtdefalult.jpgNone# %lacciDrinksddefalult.jpgNone( !%beef PizzaPizza �defalult.jpgNone&	 %Ice CreamDesrtFdefalult.jpgNone   ! 
  %Juicexdefalult.jpgNone- )%chicken burgerBurger �defalult.jpgNone0 #%Beef BurgerBurger@oP     defalult.jpgNone2 '!'Chicken pizzaPizza �pizza2.jpgChicken pizza   � �����                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              � %%#New Catagorydefault.pngNothin   P+#Murgir  mangshodefault.pngNothing   (!%#french fryfrencfry.jpgFrench frry #Drinksdefault.pngNothing #Desrtdefault.pngNothing
 #Burgerdefault.pngNothing #Pizzadefault.pngNothing
� � ������                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        �� Fried Kuttar   3Burger   'Fri
Drinks	Desrt
Burger
   Murgir  mangsho	Pizza   � ���                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       Table 3default Table 2default Table 1default   � ��H����NNNN��� ?                       9E 'MChicken pizza ��870f65bc54904c� 8#	MBeef Burger,,99729cef6b4258653b5a34812ccf0129� ;'MChicken pizza ��2acf805893fa8c664fc2d258c12849fe� ;'MChicken pizza ��99729cef6b4258653b5a34812ccf0129� E#MBeef Burger@oP     @�|     4aeda356e031a662c43 s !	Mbeef Pizza � �465eafe48223e2d66be34e0a97cd3cde ; '	MChicken pizza � �465eafe48223e2d66be34e0a97cd3cde  ? !	Mbeef Pizza � �6bf69290ae6e6becf5bf7f35c54c9ed1   '	MChicken pizza � �6bf69290ae6e6becf5bf7f35c54c9ed1  � !	Mbeef Pizza � �a5a89c5b550d31c3d97717464e09ab9b ; '	MChicken pizza � �a5a89c5b550d31c3d97717464e09a5�T !	Mbeef Pizza � �37e39a8988fccdceb235c1203cb62dbd8�S '	MChicken pizza � �37e39a8988fccdceb235c1203cb62dbd.�R 	Mlacciddd1a798c07b3277923b6c078c010c7ee5B�Q #	MBeef Burger@oP     @oP     d1a798c07b3277923b6c078c010c7ee55�P !	Mbeef Pizza � �d1a798c07b3277923b6c078c010c7ee58�O '	MChicken pizza � �d1a798c07b3277923b6c078c010c7ee5    U  U �K�2�o                                             P++YtablesqlP++Ytablesqlite_sequencesqlite_sequenceCREATE TABLE sqlite_sequence(name,seq)�!!!�tableCatagoriesCatagoriesCREATE TABLE "Catagories" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT,
	`name`	TEXT UNIQUE,
	`picture`	TEXT,
	`description`	TEXT
)3G! indexsqlite_autoindex_Catagories_1Catagories�/	�=tableFoodsFoodsCREATE TABLE "Foods" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT,
	`Name`	TEXT,
	`Catagory`	INTEGER,
	`Price`	REAL,
	`Picture`	TEXT,
	`Description`	TEXT
)q�EtableBoysBoysCREATE TABLE Boys (id INTEGER PRIMARY KEY, name TEXT, address TEXT, photo TEXT, mobile TEXT)m%%�tableDiningTablesDiningTablesCREATE TABLE DiningTables (id INTEGER PRIMARY KEY, name TEXT, type TEXT)�i99�mtableTempTransactionDetailsTempTransactionDetailsCREATE TABLE "TempTransactionDetails" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT,
	`food`	TEXT,
	`quantity`	INTEGER,
	`price`	REAL,
	`subtotal`	REAL,
	`transaction_id`	INTEGER
)   � �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 ! y yB��  ��        �5R�ItableUsersUsers
CREATE TABLE `Users` (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT,
	`name`	TEXT,
	`password`	TEXT,
	`type`	TEXT,
	`address`	TEXT,
	`mobile! �%%�-tableTransactionsTransactionsCREATE TABLE "Transactions" (
	`id`	TEXT,
	`boy`	TEXT,
	`dining`	TEXT,
	`discount`	INTEGER,
	`period`	TEXT, `Field6`	INTEGER,
	PRIMARY KEY(id)
)�"++�EtableTempTransactionTempTransactionCREATE TABLE "TempTransaction" (
	`id`	TEXT,
	`boy`	TEXT,
	`dining`	TEXT,
	PRIMARY KEY(id)
)=#Q+ indexsqlite_autoindex_TempTransaction_1TempTransaction�\J33�_tableTransactionsDetailsTransactionsDetailsCREATE TABLE "TransactionsDetails" (
	`ID`	INTEGER PRIMARY KEY AUTOINCREMENT,
	`Food`	TEXT,
	`Quantity`	INTEGER,
	`Price`	REAL,
	`TransactionID`	TEXT,
	`SubTotal`	REAL
)   �%%�	tableTransactionsTransactionsCREATE TABLE "Transactions" (
	`id`	TEXT,
	`boy`	TEXT,
	`dining`	TEXT,
	`discount`	INTEGER,
	`period`	TEXT,
	PRIMARY KEY(id)
)   9K% indexsqlite_autoindex_Transactions_1Transactions   � ����������                                                                                                                                                                                                                                                                                                                                                                                                       [fd5c8f73dc170802a88cdd4a5d867a99nazibTable 3  )6278e999b6474a08cef18287b87eb060kayasTable 1; 26a6f1cb591d144fdaf283014b2575728kayasTable 1  �79a7aa7c8180bf577aaf61af635ff432kayasTable 1  �11346452588c4391d1bbbd5c66643f42nazibTable 1� 2870f65bc54904cd8ddb4cdd8dbef124bsalamTable 2  � 2465eafe48223e2d66be34e0a97cd3cdekayasTable 1   �6bf69290ae6e6becf5bf7f35c54c9ed1salamTable 2   �a5a89c5b550d31c3d97717464e09ab9bkayasTable 3� 2936841786541e653879959639b7e78d7salamTable 20M37e39a8988fccdceb235c1203cb62dbdkayasTable 20Md1a798c07b3277923b6c078c010c7ee5nazibTable 2
   � ���mmmEEEEEE                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       �fd5c8f73dc170802a88cdd4a5d867a99  �6278e999b6474a08cef18287b87eb060� %6a6f1cb591d144fdaf283014b2575728
  L79a7aa7c8180bf577aaf61af635ff432	  '11346452588c4391d1bbbd5c66643f42# %870f65bc54904cd8ddb4cdd8dbef124b� %465eafe48223e2d66be34e0a97cd3cde   �6bf69290ae6e6becf5bf7f35c54c9ed1   �a5a89c5b550d31c3d97717464e09ab9b� %936841786541e653879959639b7e78d7$M37e39a8988fccdceb235c1203cb62dbd#M	d1a798c07b3277923b6c078c010c7ee5z  ��b                                                                                                                                                                                                                                                                                                                                                                                                                  zw}nazib123AdminDhaka4564654D:/Qt Projects/RestaurantManagement/UserPhotos/nazib.jpgz{kkkkkkkN yaaaaaaUseraaaaaaD:/Qt Projects/RestaurantManagement/UserPhotos/aaa.jpg^ #sabbir456UserDhaka57836452416D:/Qt Projects/RestaurantManagement/UserPhotos/sabbir.jpgY }nazib123AdminDhaka4564654D:/Qt Projects/RestaurantManagement/UserPhotos/nazib.jpg[ {ssdffasdUseradsfasdf67456464D:/Qt Projects/RestaurantManagement/UserPhotos/ssdf.jpg   ,}kayas123AdminDhaka454623D:/Qt ProjX }kayas123AdminDhaka454623D:/Qt Projects/RestaurantManagement/UserPhotos/kayas.jpg                   
         
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        <M!8da5494ef6003fff7fc0c5fbc86c1f00nazibTable 21413256008<M!0ea89e9d32899529777ea7ccc19874d1salamTable 21413254750<M!9b785198285f596e498a42faa14e6b70kayasTable 11413254082<M!0a956e99a71ba90f6173ff6d34a53863nazibTable 31413253924<M!9bfcfd745d2cfad2c56008b9741f3c01nazibTable 21413253845<M!59295e7cc9b07c70731e98492f5d38b8nazibTable 21413253794
   � ������                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  !kkkk   daaa
sabbirssdf	kayas	nazib   � A���;;   ��WW�tablesqlitebrowser_rename_column_new_tablesqlitebrowser_rename_column_new_tableCREATE TABLE `sqlitebrowser_rename_column_new_table` (
	`id`	TEXT,
	`boy`	TEXT,
	`dining`	TEXT,
	`discount`	INTEGER,
	`vat`	REAL,
	`period`	TEXT,
	`user`	TEXT,
	`comments`	TEXT,
	PRIMARY KEY(id)
)   �}W indexsqlite_autoindex_sqlitebrowser_rename_column_new_table_1sqlitebrowser_rename_column_new_table   =7gK% indexsqlite_autoindex_Transactions_1Transactions�Pf%%�ctableTransactionsTransactionsCREATE TABLE "Transactions" (
	`id`	TEXT,
	`boy`	TEXT,
	`dining`	TEXT,
	`discount`	INTEGER,
	`vat`	REAL,
	`period`	TEXT,
	`user`	TEXT,
	`comments`	TEXT,
	PRIMARY KEY(id)
)^U�#tablevatvat
CREATE TABLE `vat` (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT,
	`vat`	REAL
))T= indexsqlite_autoindex_Users_1Users�<S�WtableUsersUsersCREATE TABLE "Users" (
	`id`	INTEGER PRIMARY KEY AUTOINCREMENT,
	`name`	TEXT UNIQUE,
	`password`	TEXT,
	`type`	TEXT,
	`address`	TEXT,
	`mobile`	TEXT,
	`photo`	TEXT
)   2 ��H��T��j2� � � i                                                      B #	MBe5I !	Mbeef Pizza �2b4d9291e6320ad7b2ac1551961d39db �8H '	MChicken pizza �2b4d9291e6320ad7b2ac1551961d39db �5G !	Mbeef Pizza �8be79a30acd3ef663096e1d   5 	MIce CreamF0a956e99a71ba90f6173ff6d5� !	Mbeef Pizza �af0a32d373300540ae20ca8cfe06b6bf �8� '	MChicken pizza �af0a32d373300540ae20ca8cfe06b6bf �5� !	Mbeef Pizza �2c82ba4c2dd8eb43f6949ab265d0a596 �8� '	MChicken pizza �2c82ba4c2dd8eb43f6949ab265d0a596 �9� )	Mchicken burger �1f121763540ec33b5d724e51030dc035 �B� #	MBeef Burger@oP     1f121763540ec33b5d724e51030dc035@oP     5� !	Mbeef Pizza �64eed3736def7015dd845898f7701269 �8� '	MChicken pizza �64eed3736def7015dd845898f7701269 �9� )	Mchicken burger �c33704ebb59de5edc6af650ce6172e7d �B� #	MBeef Burger@oP     c33704ebb59de5edc6af650ce6172e7d@oP     5� !	Mbeef Pizza �63a7c50967d1a7803d6c381123939191 �8� '	MChicken pizza �63a7c50967d1a7803d6c381123939191 �      ����������� � � y ;                     <M!34b321531e54520ef509d385842126a2salamTable 21413253692<M!b90184865aecf49984cda3ff3803aeefsalamTable 11413253495<M!24f222e87de10e83911cd2485d6dc08bsalamTable 21413253408<M!b746b5a04ad695e7b6e1ee7aa67dc23dsalamTable 21413252872<M!b4ad1e4479d443ce8cc894194fd   >!b4ad1e4479d443ce8cc894194fde19f2salamTable 21413252510   >!b746b5a04ad695e7b6e1ee7aa67dc23dsalamTable 21413252872   >!24f222e87de10e83911cd2485d6dc08bsalamTable 21413253408   >!b90184865aecf49984cda3ff3803aeefsalamTable 11413253495   >!34b321531e54520ef509d385842126a2salamTable 21413253692   >!59295e7cc9b07c70731e98492f5d38b8nazibTable 21413253794   >!9bfcfd745d2cfad2c56008b9741f3c01nazibTable 21413253845   >!0a956e99a71ba90f6173ff6d34a53863nazibTable 31413253924   >!9b785198285f596e498a42faa14e6b70kayasTable 11413254082   >!0ea89e9d32899529777ea7ccc19874d1salamTable 21413254750   >!8da5494ef6003fff7fc0c5fbc86c1f00nazibTable 21413256008
       � �BB�����������������                                                                                                                                                                                                        8da5494ef6003fff7fc0c5fbc86c1f00  �0ea89e9d32899529777ea7ccc19874d1  �9b785198285f596e498a42faa14e6b70  �0a956e99a71ba90f6173ff6d34a53863  t9bfcfd745d2cfad2c56008b9741f3c01  O59295e7cc9b07c70731e98492f5d38b8  *34b321531e54520ef509d385842126a2  b90184865aecf49984cda3ff3803aeef  �24f222e87de10e83911cd2485d6dc08b  �b746b5a04ad695e7b6e1ee7aa67dc23d  �b4ad1e4479d443ce8cc894194fde19f2  q673f4775551223cf05155b7980dd5879
  Le3b4a91ec792a6d526652c475220a727	  'e686486a6dce93ee82d8c779a9e66fa2  fac1518d6a63b106ef97320e599b1cdd   �2b4d9291e6320ad7b2ac1551961d39db   �8be79a30acd3ef663096e1dffdb90d4a   �a9cc64388ab26b6f65e5b1f794911468   nf418b83e288d3d7492ce890f138303a2   I0d2cd42faf9c160aaad490a8f1678146   $35574acbaf38e4e8649b5d7667663a4a   < �k��<                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        G	M!af0a32d373300540ae20ca8cfe06b6bfsalamTable 21413791312sabbirL	M!2c82ba4c2dd8eb43f6949ab265d0a596salamTable 2
1413789879ssdfadfadsfJ	M!1f121763540ec33b5d724e51030dc035salamTable 21413785635nazibgjhgJ	M!64eed3736def7015dd845898f7701269nazibTable 21413785315nazibggggK	M!c33704ebb59de5edc6af650ce6172e7dkayasTable 11413784003nazibHelloF	M!63a7c50967d1a7803d6c381123939191salamTable 21413783808nazib
   # mH��#�                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               $Maf0a32d373300540ae20ca8cfe06b6bf$M2c82ba4c2dd8eb43f6949ab265d0a596$M1f121763540ec33b5d724e51030dc035$M64eed3736def7015dd845898f7701269$Mc33704ebb59de5edc6af650ce6172e7d#M	63a7c50967d1a7803d6c381123939191   / ��X��g/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       5� !	Mbeef Pizza �8da5494ef6003fff7fc0c5fbc86c1f00 �8� '	MChicken pizza �8da5494ef6003fff7fc0c5fbc86c1f00 �2� 	MIce CreamF0ea89e9d32899529777ea7ccc19874d1F9� )	Mchicken burger �0ea89e9d32899529777ea7ccc19874d1 �B� #	MBeef Burger@oP     0ea89e9d32899529777ea7ccc19874d1@oP     5� !	Mbeef Pizza �0ea89e9d32899529777ea7ccc19874d1 �8� '	MChicken pizza �0ea89e9d32899529777ea7ccc19874d1 �2�
 	MIce CreamF9b785198285f596e498a42faa14e6b70F