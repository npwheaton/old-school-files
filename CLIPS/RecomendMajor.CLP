(deffunction ask (?question)
   (printout t "On a scale of 1-5, 1 being no interest and 5 being highly interested in " ?question crlf)
   (bind ?answer (read))
  ?answer) 

(deftemplate completed
(slot CSCI (default Not-Tested))
(slot SE (default Not-Tested))
(slot CS (default Not-Tested)))

(deffacts WhenDone
(completed(CSCI Not-Tested) (SE Not-Tested) (CS Not-Tested))
)
(deftemplate major
(slot Dname (type LEXEME))
(slot interest1 (default incomplete))
(slot interest2 (default incomplete))
(slot interest3 (default incomplete))
(slot interest4 (default incomplete))
(slot interest5 (default incomplete))
(slot interest6 (default incomplete))
(slot career1 (default incomplete))
(slot career2 (default incomplete))
(slot Points (type NUMBER) (default 0))
(slot counter (type NUMBER) (default 0)))

(deffacts Areas-Of-Study
(major(Dname Computer-Science)(interest1 incomplete)(interest2 incomplete)(interest3 incomplete)
(interest4 incomplete)(interest5 incomplete)(interest6 incomplete)(career1 incomplete)
(career2 incomplete)(Points 0)(counter 0))

(major(Dname Software-Engineering)(interest1 incomplete)(interest2 incomplete)(interest3 incomplete)
(interest4 incomplete)(interest5 incomplete)(interest6 incomplete)(career1 incomplete)
(career2 incomplete)(Points 0)(counter 0))

(major(Dname Cyber-Security)(interest1 incomplete)(interest2 incomplete)(interest3 incomplete)
(interest4 incomplete)(interest5 incomplete)(interest6 incomplete)(career1 incomplete)
(career2 incomplete)(Points 0)(counter 0)))

(defrule interest1
?x<- (major(Dname Computer-Science) (interest1 incomplete) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h)(Points ?p) (counter ?c))
?y<- (major(Dname Software-Engineering) (interest1 incomplete) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h)(Points ?p) (counter ?c))

=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How would you like programming your own game, website or app? "))
(bind ?addto(+ ?response ?p))
(retract ?x ?y)
(assert (major(Dname Computer-Science) ( interest1 complete) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?addto)(counter ?nex)))
(assert (major(Dname Software-Engineering)( interest1 complete) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?addto)(counter ?nex))))

(defrule interest2
?x<- (major(Dname Computer-Science) (interest2 incomplete) ( interest1 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?p) (counter ?c))
?y<- (major(Dname Software-Engineering) (interest2 incomplete) ( interest1 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h)  (Points ?p) (counter ?c))

=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How interested are you in A.I and machine learning? "))
(bind ?addto(+ ?response ?p))
(retract ?x ?y)
(assert (major(Dname Computer-Science)( interest2 complete) ( interest1 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?addto)(counter ?nex)))
(assert (major(Dname Software-Engineering)( interest2 complete) ( interest1 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?addto)(counter ?nex))))

(defrule CSCI-Interest3
?x<- (major(Dname Computer-Science) (interest3 incomplete) ( interest1 ?b) (interest2 ?a) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h)  (Points ?p) (counter ?c))
=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How much do you like math? "))
(bind ?addto(+ ?response ?p))
(retract ?x )
(assert (major(Dname Computer-Science)( interest3 complete) ( interest1 ?b) (interest2 ?a) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?addto)(counter ?nex))))

(defrule CSCI-Interest4
?x<- (major(Dname Computer-Science) (interest4 incomplete) ( interest1 ?d) (interest2 ?a) (interest3 ?b) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h)  (Points ?p) (counter ?c))
=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How interested are you in learning about useful programming languages?"))
(bind ?addto(+ ?response ?p))
(retract ?x )
(assert (major(Dname Computer-Science)( interest4 complete) ( interest1 ?d) (interest2 ?a) (interest3 ?b) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h)  (Points ?addto)(counter ?nex))))

(defrule CSCI-Interest5
?x<- (major(Dname Computer-Science) (interest5 incomplete) ( interest1 ?e) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?p) (counter ?c))
=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How interested are you in learning about Computer algorithms"))
(bind ?addto(+ ?response ?p))
(retract ?x )
(assert (major(Dname Computer-Science)( interest5 complete) ( interest1 ?e) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?addto)(counter ?nex))))

(defrule CSCI-Interest6
?x<- (major(Dname Computer-Science) (interest6 incomplete) ( interest1 ?f) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (career1 ?g) (career2 ?h) (Points ?p) (counter ?c))
=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How interested are you in learning about Computer graphics and animation"))
(bind ?addto(+ ?response ?p))
(retract ?x )
(assert (major(Dname Computer-Science)( interest6 complete) ( interest1 ?f) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (career1 ?g) (career2 ?h) (Points ?addto)(counter ?nex))))

(defrule SE-interest3
?x<- (major(Dname Software-Engineering) (interest3 incomplete) ( interest1 ?b) (interest2 ?a) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h)  (Points ?p) (counter ?c))

=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How interested are you in learning about how software is created and modeled?"))
(bind ?addto(+ ?response ?p))
(retract ?x)
(assert (major(Dname Software-Engineering)( interest3 complete) ( interest1 ?b) (interest2 ?a) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h)  (Points ?addto)(counter ?nex))))

(defrule SE-interest4
?x<- (major(Dname Software-Engineering) (interest4 incomplete) ( interest1 ?d) (interest2 ?a) (interest3 ?b) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?p) (counter ?c))

=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How interested are you in learning about the different types of Software?"))
(bind ?addto(+ ?response ?p))
(retract ?x)
(assert (major(Dname Software-Engineering)( interest4 complete) ( interest1 ?d) (interest2 ?a) (interest3 ?b) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?addto)(counter ?nex))))

(defrule SE-interest5
?x<- (major(Dname Software-Engineering) (interest5 incomplete) ( interest1 ?e) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?p) (counter ?c))

=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How interested are you in learning about designing a U.I and G.U.I?"))
(bind ?addto(+ ?response ?p))
(retract ?x)
(assert (major(Dname Software-Engineering)( interest5 complete) ( interest1 ?e) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?addto)(counter ?nex))))

(defrule SE-interest6
?x<- (major(Dname Software-Engineering) (interest6 incomplete) ( interest1 ?f) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (career1 ?g) (career2 ?h) (Points ?p) (counter ?c))

=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How much do you like solving puzzles?"))
(bind ?addto(+ ?response ?p))
(retract ?x)
(assert (major(Dname Software-Engineering)( interest6 complete) ( interest1 ?f) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (career1 ?g) (career2 ?h) (Points ?addto)(counter ?nex))))

(defrule career1
(declare(salience 100))
?x<- (major(Dname Computer-Science) (career1 incomplete) ( interest1 ?g) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career2 ?h)(Points ?p) (counter ?c))
?y<- (major(Dname Software-Engineering) (career1 incomplete) ( interest1 ?g) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career2 ?h) (Points ?p) (counter ?c))

=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How interested are you in Working for google, microsoft or a tech company as software developer? "))
(bind ?addto(+ ?response ?p))
(retract ?x ?y)
(assert (major(Dname Computer-Science)( career1 complete) ( interest1 ?g) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career2 ?h) (Points ?addto)(counter ?nex)))
(assert (major(Dname Software-Engineering)( career1 complete) ( interest1 ?g) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career2 ?h) (Points ?addto)(counter ?nex))))

(defrule career2
(declare(salience 50))
?x<- (major(Dname Computer-Science) (career2 incomplete) ( interest1 ?h) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (Points ?p) (counter ?c))
?y<- (major(Dname Software-Engineering) (career2 incomplete)( interest1 ?h) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (Points ?p)(counter ?c))

=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How interested are you in Working in a group of people on big projects that require alot of teamwork, planning and brainstorming"))
(bind ?addto(+ ?response ?p))
(retract ?x ?y)
(assert (major(Dname Computer-Science)( career2 complete) ( interest1 ?h) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (Points ?addto)(counter ?nex)))
(assert (major(Dname Software-Engineering)( career2 complete) ( interest1 ?h) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (Points ?addto)(counter ?nex))))

(defrule CS-interest1
?x<- (major(Dname Cyber-Security) (interest1 incomplete) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?p) (counter ?c))

=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How interested are you in Hacking into a computer, or website, or game?"))
(bind ?addto(+ ?response ?p))
(retract ?x)
(assert (major(Dname Cyber-Security)( interest1 complete) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?addto)(counter ?nex))))


(defrule CS-interest2
?x<- (major(Dname Cyber-Security) (interest2 incomplete) (interest1 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?p) (counter ?c))

=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How interested are you in learning about Data encryption and cryptography?"))
(bind ?addto(+ ?response ?p))
(retract ?x)
(assert (major(Dname Cyber-Security)( interest2 complete) ( interest1 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?addto)(counter ?nex))))

(defrule CS-interest3
?x<- (major(Dname Cyber-Security) (interest3 incomplete) ( interest1 ?b) (interest2 ?a) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h)(Points ?p) (counter ?c))

=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How interested are you in learning about Network security?"))
(bind ?addto(+ ?response ?p))
(retract ?x)
(assert (major(Dname Cyber-Security)( interest3 complete) ( interest1 ?b) (interest2 ?a) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h)  (Points ?addto)(counter ?nex))))

(defrule CS-interest4
?x<- (major(Dname Cyber-Security) (interest4 incomplete) ( interest1 ?d) (interest2 ?a) (interest3 ?b) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?p) (counter ?c))

=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How interested are you in learning about How DDoS, malware, and viruses work?"))
(bind ?addto(+ ?response ?p))
(retract ?x)
(assert (major(Dname Cyber-Security)( interest4 complete) ( interest1 ?d) (interest2 ?a) (interest3 ?b) (interest5 ?e) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?addto)(counter ?nex))))

(defrule CS-interest5
?x<- (major(Dname Cyber-Security) (interest5 incomplete) ( interest1 ?e) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?p) (counter ?c))

=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How interested are you in learning about Firewalls and penetration testing?"))
(bind ?addto(+ ?response ?p))
(retract ?x)
(assert (major(Dname Cyber-Security)( interest5 complete) ( interest1 ?e) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest6 ?f) (career1 ?g) (career2 ?h) (Points ?addto)(counter ?nex))))

(defrule CS-interest6
?x<- (major(Dname Cyber-Security) (interest6 incomplete) ( interest1 ?f) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (career1 ?g) (career2 ?h) (Points ?p) (counter ?c))

=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How interested are you in learning about Cloud networking?"))
(bind ?addto(+ ?response ?p))
(retract ?x)
(assert (major(Dname Cyber-Security)( interest6 complete) ( interest1 ?f) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (career1 ?g) (career2 ?h) (Points ?addto)(counter ?nex))))

(defrule CS-career1
?x<- (major(Dname Cyber-Security) (career1 incomplete) ( interest1 ?g) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career2 ?h) (Points ?p) (counter ?c))

=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "How interested are you in Working for government to improve national security?"))
(bind ?addto(+ ?response ?p))
(retract ?x)
(assert (major(Dname Cyber-Security)( career1 complete) ( interest1 ?g) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career2 ?h) (Points ?addto)(counter ?nex))))

(defrule CS-career2
?x<- (major(Dname Cyber-Security) (career2 incomplete) ( interest1 ?h) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (Points ?p) (counter ?c))

=>
(bind ?nex(+ ?c 1))
(bind ?response(ask "Working in a group or sometimes alone to create and test security systems?"))
(bind ?addto(+ ?response ?p))
(retract ?x)
(assert (major(Dname Cyber-Security)( career2 complete) ( interest1 ?h) (interest2 ?a) (interest3 ?b) (interest4 ?d) (interest5 ?e) (interest6 ?f) (career1 ?g) (Points ?addto)(counter ?nex))))


(defrule CSCIassessed
(major(Dname Computer-Science)(counter 8))
?t <- (completed(CSCI Not-Tested) (SE ?a) (CS ?b))

=>
(retract ?t)
(assert (completed(CSCI Tested) (SE ?a) (CS ?b))))

(defrule SEassessed
(major(Dname Software-Engineering)(counter 8))
?t <- (completed(SE Not-Tested)(CSCI ?a)(CS ?b))
=>
(retract ?t)
(assert (completed(SE Tested) (CSCI ?a)(CS ?b))))

(defrule CSassessed
(major(Dname Cyber-Security)(counter 8))
?t <- (completed(CS Not-Tested)(CSCI ?a)(SE ?b))
=>
(retract ?t)
(assert (completed(CS Tested)(CSCI ?a)(SE ?b))))

(defrule FindMajor
(completed(CS Tested) (CSCI Tested) (SE Tested))
(major(Dname ?x)(Points ?p&:(> ?p 23)))
(not(major(Dname ?y&~?x)(Points ?q&:(> ?q ?p))))

=>
(printout t "Congratulations, The Department of Computer Science and Information Technology might be right for you. A major that would fit you is  " ?x crlf))

(defrule noMajor
(completed(CS Tested) (CSCI Tested) (SE Tested))
(major(Dname ?x)(Points ?p&:(> 23 ?p)))
(not(major(Dname ?y&~?x)(Points ?q&:(> ?q ?p))))

=>
(printout t "The Department of Computer Science and Information Technology might not be the best fit for you." crlf))

