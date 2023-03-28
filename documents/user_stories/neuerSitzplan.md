user 

möchte einen neuen sitzplan mit einer variablen anzahl and reihen and spalten erstellen können und die auswahl zwischen 3 erlaubten belegungsmustern haben

damit die gewählten sitzplätze der studierenden gespeichert und später ausgelesen werden können


# Acceptance Criteria 1
## situation
der user befindet sich im hauptmenu

## event
der user wählt den menupunkt "neuer sitzplan"

## resultat
der user wird aufgefordert werte für reihen und spalten einzugeben


# Acceptance Criteria 2
## situation
der user wird aufgefordert werte für reihen und spalten einzugeben

## event
eine ungültige (wert <= 0 oder keine (natürliche)zahl) eingabe ist erfolgt

## resultat
der user wird aufgefordert die eingabe zu wiederholen


# Acceptance Criteria 3
## situation
der user wird aufgefordert werte für reihen und spalten einzugeben

## event    
eine gültige eingabe ist erfolgt

## resultat
erstelle ein einen char** mit der größe reihe*spalten und fordere den user auf, ein belegungsmuster(100%, "50%", "25%") auszuwählen


# Acceptance Criteria 4
## situation
der user wird aufgefordert das belegungsmuster auszuwählen

## event
eine ungültige auswahl ist erfolgt

## resultat
der user wird aufgefordert die eingabe zu wiederholen


# Acceptance Criteria 5
## situation
der user wird aufgefordert das belegungsmuster auszuwählen

## event
eine gültige auswahl ist erfolgt

## resultat
der char** wird entsprechend des gewählten belegungsmusters beschrieben (":\0" für erlaubte- bzw. "\0" für verbotene sitzplätze) und der user wird aufgefordert eine studierendenkennung einzugeben, dessen sitzplatz als nächstes zugewiesen werden soll


# Acceptance Criteria 6
## situation
der user wird aufgefordert eine studierendenkennung oder einen sitzplatz einzugeben

## event
- der user bricht den vorgang mit der eingabe von "-save" ab 
- (oder) der user hat gerade einen sitzplatz eingetragen und es sind keine freien sitzplätze mehr verfügbar

## resultat
der user wird aufgefordert einen namen für die datei einzugeben, in die der sitzplan gespeichert werden soll


# Acceptance Criteria 7
## situation
der user wird aufgefordert einen namen für die datei einzugeben, in die der sitzplan gespeichert werden soll

## event
ein ungültiger dateiname (leerer string, ungültiger charakter) wird eingegeben

## resultat
der user wird aufgefordert die eingabe zu wiederholen


# Acceptance Criteria 8
## situation
der user wird aufgefordert einen namen für die datei einzugeben, in die der sitzplan gespeichert werden soll

## event
ein gültiger dateiname wird eingegeben

## resultat
eine datei mit dem eingegeben namen wird erstellt und der sitzplan wird nach dem format "///sitzplan///*reihen_wert*,*spalten_wert*,0:*studierendenkennung*,1:,2:*studierendenkennung*,...." in die datei geschrieben, gespeichert und der user wird zurück ins hauptmenu geleitet


# Acceptance Criteria 9
## situation
der user hat einen gültigen dateinamen eingegeben

## event
die datei konnte nicht erstellt, beschrieben oder gespeichert werden

## resultat
benachrichtige den user über die art des fehlers und beende das programm


# Acceptance Criteria 10
## situation
der user befindet sich an einem beliebigen punkt in der erstellung eines neuen sitzplans

## event
der user bricht den vorgang mit der eingabe "-abort" ab

## resultat
der user wird zurück ins hauptmenu geleitet