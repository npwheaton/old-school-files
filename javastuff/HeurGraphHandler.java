import java.awt.Color;
import java.awt.*;
import javax.swing.JPanel;
import java.util.Random;
public class HeurGraphHandler extends JPanel { 
private int vertices[][];
private Graphset graph;
private Grapheuristic highest;
private twodArray coors;
    
    public HeurGraphHandler(Graphset graph){ 
        vertices = new int[graph.sendSize()][graph.sendSize()];
        this.graph = graph;
        
    }
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        for (int i= 0; i<graph.sendSize();i++)
            {g.setColor(Color.BLACK);
            g.drawRect(vertices[i][0],vertices[i][1], 10, 10);
            g.fillRect(vertices[i][0],vertices[i][1], 10, 10);
             if(highest!=null)
             {for (int j= 0; j< graph.sendSize(); j++)
                    {if(highest.getchromogene(i, j)==1)
                        {
                          g.drawLine(vertices[i][0], vertices[i][1], vertices[j][0], vertices[j][1]);
                          g.drawString(graph.Atposition(i, j), (vertices[i][0] + vertices[j][0])/2, (vertices[i][1] + vertices[j][1])/2);
                        }

                    }
                 

             }
        
    }
    }
    public void generategraph(){
        for (int i= 0; i<graph.sendSize();i++)
            {vertices[i][0]= coors.sendCoordinates(i, 0);
            vertices[i][1]= coors.sendCoordinates(i, 1);;
        }
    }
    public void gethighest(Grapheuristic gp){
        highest = gp;
    }
    public void get2dArray(twodArray arrayrecieved){
         coors = arrayrecieved;
         generategraph();
    }
    }
