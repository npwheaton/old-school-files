;;;======================================================
;;;   Movie Recommendation program
;;;   by Nate Wheaton
;;;
;;;     The program determines which movies that best
;;;     the user from a list of movies out in theatres
;;;======================================================
;;****************
;;* DEFFUNCTIONS *
;;****************

(deffunction singleAnswer (?question)
   (printout t ?question crlf)
   (bind ?answer (read))
   ?answer)

(deffunction multiAnswer (?question)
   (printout t ?question crlf)
   (bind $?answer (read))
   $?answer)

(deftemplate movies
  (slot title)
  (multislot genre)
  (slot rating)
  (multislot starring)
  (multislot directors)
  (slot critic)
  (slot audience)
  (slot points (TYPE NUMBER))

(deftemplate ask
  (multislot question))
(deffacts Qs
  (ask (question "What movie genres do you prefer"))
  (ask (question "What movie rating would you most prefer: G PG PG13 R NC17"))
  (ask (question "What actors do you like to see? For example Brad-Pitt"))
  (ask (question "What directors do you like"))
  (ask (question "Do you care about how the potential movie is rated by critics"))
  (ask (question "Do you care about how the potential movie is rated by the audience"))
(defrule Load-in
  (declare (salience 1000))
  =>
  (load-facts "movies.dat"))


(defrule GenresLiked
  ?Q<-(question "What movie genres do you prefer")
 ?g<-( movies (genre (multiAnswer $?Q) (points ?p))
 =>
  (modify ?g (points (+ ?p 1))))

(defrule RatingLiked
  ?Q<-(question "What movie rating would you most prefer: G PG PG13 R NC17")
 ?g<-(movies (rating (singleAnswer ?Q) (points ?p))
 =>
  (modify ?g (points (+?p 1))))

(defrule StarsLiked
  ?Q<-(question "What actors do you like to see? For example Brad-Pitt")
 ?g<-( movies (starring (multiAnswer $?Q) (points ?p))
 =>
  (modify ?g (points (+?p 1))))

(defrule DirectorsLiked
  ?Q<-(question "What directors do you like")
 ?g<-(movies (directors (multiAnswer $?Q) (points ?p))
 =>
  (modify ?g (points (+?p 1))))

(defrule CriticOpinion
  ?Q<-(question "Do you care about how the potential movie is rated by critics")
 ?a<-(singleAnswer ?Q)
(critic ?c&:(> ?c 69)
test(eq ?a "yes")
 =>
  (modify ?g (points (+?p 1))))

(defrule audienceOpinion
  ?Q<-(question "Do you care about how the potential movie is rated by the audience")
 ?a<-(singleAnswer ?Q)
(audience ?au&:( >?au 69)
test(eq ?a "yes")
 =>
  (modify ?g (points (+?p 1))))

(defrule Recommend
  (declare (salience -100)
  ?ti<-(title ?t)
  ?po<-(points ?p)
  =>
(printout t "You should see the movie " ?ti "It was a " ?po "0% match"  crlf)