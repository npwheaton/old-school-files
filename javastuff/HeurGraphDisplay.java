import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class HeurGraphDisplay extends JFrame {
    private JTextArea high;
    private HeurGraphHandler gh;
        
    public HeurGraphDisplay(Graphset graph){
        super("Minimum Label Spanning tree Heuristic Alorithm");
       setLayout(new BorderLayout());
       pack();
       high = new JTextArea();
       gh = new HeurGraphHandler(graph);
       high.setEditable(false);
       add(high, BorderLayout.SOUTH);
       add(gh, BorderLayout.CENTER);
       high.setText("Fitness: ");
       setSize(800, 600);
       setVisible(true);
       setLocationRelativeTo(null);
       addWindowListener(new WindowAdapter() {
        public void windowClosing(WindowEvent event) {
          System.exit(0);
        }
      });
    }
  
public void Send2dArray(twodArray array){
    gh.get2dArray(array);
}
public void SendHeur(Grapheuristic gph){
    gh.gethighest(gph);
}
  public void stats( int High, Grapheuristic hghest){
    gh.gethighest(hghest);
    String temp2 = "Fitness: " + High;
    high.setText(temp2);
    gh.repaint();
    }
}
