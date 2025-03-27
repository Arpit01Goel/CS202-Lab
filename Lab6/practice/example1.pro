happy(me) :- rains.
playGuitar(me) :- happy(me).
singSong(me):- playGuitar(me).
sleep(me):- rains.


rains:- true.