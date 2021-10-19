import java.util.Iterator;
import java.util.LinkedList;
import java.awt.*;

import javax.swing.JPanel;

public class DotHandler extends JPanel { 
LinkedList<Dot> dots = new LinkedList<Dot>();

public DotHandler(){ 
}
public void paintComponent(Graphics g){
    super.paintComponent(g);
    g.drawLine(20, 525, 20, 20);
    g.drawLine(20, 525, 2000, 525);
    render(g);
}
public void render(Graphics g){
    for (Iterator<Dot> all = dots.iterator(); all.hasNext(); ) {
        Dot d = (Dot) all.next();
        d.render(g);
        } 
}
public void insertdot(Dot d) {dots.add(d);}

}
