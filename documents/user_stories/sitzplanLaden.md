user 

möchte vorher erstellte sitzpläne laden können

damit auch nachträglich noch zu benachrichtigende Personen ermittelt werden werden können


# Acceptance Criteria 1
## situation 
der user befindet sich im hauptmenu

## event
der user wählt den menupunkt "sitzplan laden"

## resultat
der user wird aufgefordert einen dateinamen einzugeben


# Acceptance Criteria 2
## situation
der user wird aufgefordert einen dateinamen einzugeben

## event
- ein nicht existenter dateiname wurde eingegeben
- (oder) die angegebene datei ist kein sitzplan (beginnt nicht mit ///sitzplan///)

## resultat
der user wird aufgefordert die eingabe zu wiederholen


# Acceptance Criteria 3
## situation
der user wird aufgefordert einen dateinamen einzugeben

## event
ein korrekter dateiname für einen sitzplan wurde eingegeben

## resultat
es wird versucht den sitzplan aus dem file in ein char** zu rekonstruiren


# Acceptance Criteria 4
## situation
es wird versucht den inhalt den sitzplan-files in ein char** zu rekonstruieren

## event
es existieren keine gültigen werte für reihen/spalten

## resultat
der user wird informiert, dass die gewählte datei kein gültiger sitzplan ist und wird zurück in das hauptmenu geleitet


# Acceptance Criteria 5
## situation
es wird versucht den inhalt den sitzplan-files in ein char** zu rekonstruieren

## event
es existiert nicht die korrekte anzahl an sitzplätzen für die angegebenen reihen/spalten

## resultat
der user wird informiert, dass die gewählte datei kein gültiger sitzplan ist und wird zurück in das hauptmenu geleitet


# Acceptance Criteria 6
## situation
es wird versucht den inhalt den sitzplan-files in ein char** zu rekonstruieren

## event
der char** konnte anhand des files korrekt rekonstruiert werden

## resultat
der user wird aufgefordert eine studierendenkennung einzugeben, dessen (indirekte)nachbarn abgefragt werden sollen


# Acceptance Criteria 7
## situation
der user wird aufgefordert einen dateinamen einzugeben

## event
der user bricht den vorgang mit der eingabe "-abort" ab

## resultat
der user wird zurück ins hauptmenu geleitet