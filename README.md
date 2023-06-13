# MERILNA NAPRAVA

## Navodila
S pomočjo Arduina in ustreznih senzorjev ter vezja skonstruirajte samostojno napravo za merjenje in prikaz izbrane fizikalne veličine:

a) Temperatura in vlago(v °C in %) <br>
b) Sila (v N) <br>
c) Tlak v tekočini (v Bar), <br>
d) Vlažnost zemlje/zraka (v %), <br>
e) Osvetljenost/svetilnost (v Lux), <br>
f) Jakost mag. polja (B, H), <br>
g) Detekcijo kovine/snovi (da/ne), <br>
h) Hitrost/smer vetra (km/h, m/s, vozlov), <br>
i) Razdalja (cm), <br>
j) Pospeška (g, 2g, 4g, 8g), <br>
k) Kota (v °). <br>
l) drugo ...

Veličine se morajo izpisati na primernem LCD zaslonu ali OLED prikazovalniku v realnem času in imeti usterzne enote. 

<br />

## Kosovnica
| Število kosov | Komponent             |                                         
|:-------------:|-----------------------|   
|       1       | 1.3 inch OLED display |                    
|       1       | BMP 180               |
|       1       | Sončna celica         | 
|       1       | Arduino NANO          | 
|       1       | DHT11                 |
|       2       | Stikalo               |
|       1       | Zener dioda BA159     |
|       1       | Lithium Ion Battery   |


<br />

## Opis izdelka
Vremenska postaja, ki v živo meri:
•	Temperaturo,<br>
•	Vlažnost,<br>
•	Zračni tlak in <br>
•	Napetost, katero proizvaja sončna celica.<br>
Napaja jo litij-ionska baterija, katero prav tako polni sončna celica. Če je vremenska postaja izpostavljena soncu, je proizvedena napetost celice dovolj visoka, da napaja celotno vezje. 

<br />

## Vezalna shema
![shema](https://github.com/Snicl/projekt_merilna_naprava/assets/123487347/0b2cd8a7-22b3-4638-853b-544ebca75043)
 
<br />

## Videoposnetek
https://github.com/Snicl/projekt_merilna_naprava/assets/123487347/74537665-8dd4-4dcc-af0f-e70a80b8e087

<br />

## Komentar
Vremenska postaja deluje brezhibno. Temperaturo in zračni tlak meriva s senzorjem BMP180, vlažnost z DHT11, napetost na sončni celici pa direktno preko analognega vhoda. Za izpis vrednosti pa sva uporabila 1,31'' OLED zaslon. Postajo napajava z litij-ionsko baterijo in sončno celico.
Meritve so točne in v mejah napake. Med baterijo in arduinom (Nano) sva vezala stikalo, da lahko ročno izklopimo celotno postajo. Da sončna celica nebi prenapolnila baterije, sva zaporedno med sončno celico in baterijo vezala stikalo, ki mora biti izključeno, ko vremenska postaja ni v upora. Prav tako sva med sončno celico in baterijo vezala diodo, ki prepreči, da bi se baterija praznila skozi  sončno celico. Ta problem bi lahko rešila tudi s tranzistorjem.



