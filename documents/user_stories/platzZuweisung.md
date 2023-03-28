user

möchte studierenden anhand deren studierendenkennung einen sitzplatz zuweisen können

damit im krankheitsfall vorherhige sitzplätze ermittelt werden können


# Acceptance Criteria 1
## situation
der user wird aufgefordert eine studierendenkennung einzugeben

## event
eine ungültige gültige studienkennung wird eingegeben

## resultat
der user wird aufgefordert die eingabe zu wiederholen


# Acceptance Criteria 2
## situation
der user wird aufgefordert eine studierendenkennung einzugeben

## event
eine gültige studienkennung wird eingegeben

## resultat
der user wird aufgefordert einen sitzplatz auszuwählen


# Acceptance Criteria 3
## situation
der user wird aufgefordert einen sitzplatz auszuwählen

## event
ein nicht existenter sitzplatz oder ein unerlaubter sitzplatz wurde ausgewählt 

## resultat
der user wird aufgefordert die eingabe zu wiederholen


# Acceptance Criteria 4
## situation
der user wird aufgefordert einen sitzplatz auszuwählen

## event
ein gültiger sitzplatz wurde ausgewählt

## resultat
der char** wird im ausgewählten index entsprechend dem format "*studierendenkennung*\0" beschrieben und solange es noch freie plätze gibt, wird der user erneut aufgefordert, eine studierendenkennung einzugeben. ansonsten wird der user aufgefordert einen dateinamen anzugeben