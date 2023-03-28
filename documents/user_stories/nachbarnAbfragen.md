user

möchte anhand einer studierendenkennung dessen (indirekte)nachbarn in einem sitzplan finden

damit die im krankheitsfall zu benachrichtigenden personen ermittelt werden können


# Acceptance Criteria 1
## situation
der user wird aufgefordert die studierendenkennung einzugeben von welcher die (indirekten) nachbarn ermittelt werden sollen

## event
der user gibt eine ungültige (nicht im raum befindliche) studierendenkennung ein

## resultat
der user wird aufgefordert die eingabe zu wiederholen


# Acceptance Criteria 2
## situation	
der user wird aufgefordert die studierendenkennung einzugeben von welcher die (indirekten) nachbarn ermittelt werden sollen

## event
der user gibt eine gültige studierendenkennung ein

## resultat
der user wird gefragt ob er die direkten(1) oder indirekten(2) nachbarn ermitteln möchte


# Acceptance Criteria 3
## situation
der user wird gefragt ob er die direkten oder indirekten nachbarn ermitteln möchte

## event
der user trifft eine ungültige auswahl

## resultat
der user wird aufgefordert die eingabe zu wiederholen


# Acceptance Criteria 4
## situation
der user wird gefragt ob er die direkten oder indirekten nachbarn ermitteln möchte

## event
der user wählt die direkten nachbarn

## resultat
der user erhält eine liste mit den direkten nachbarn und wird erneut aufgefordert eine studierendenkennung einzugeben


# Acceptance Criteria 5
## situation
der user wird gefragt ob er die direkten oder indirekten nachbarn ermitteln möchte

## event
der user wählt die indirekten nachbarn

## resultat
der user erhält eine liste mit den indirekten nachbarn und wird erneut aufgefordert eine studierendenkennung einzugeben


# Acceptance Criteria 6
## situation
der user wird aufgefordert eine studierendenkennung einzugeben von welcher die (indirekten) nachbarn ermittelt werden sollen

## event
der user bricht den vorgang mit der eingabe "-abort" ab

## resultat
der user wird zurück ins hauptmenu geleitet