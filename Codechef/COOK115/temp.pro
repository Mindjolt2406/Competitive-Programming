rev([],X,X).
rev([H|X],Y,Z) :- rev(X,[H|Y],Z).
