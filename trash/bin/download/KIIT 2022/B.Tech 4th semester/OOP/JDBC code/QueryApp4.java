// TechRef pg19.16
import java.sql.*;
import java.awt.*;
import java.awt.event.*;
public class QueryApp4 extends Frame implements ActionListener
{
	TextField pid;
	TextField pname;
	Button next;
	Panel p;

	static ResultSet result;
	static Connection con;
	static Statement stat;

	public QueryApp4()
	{
		super("The Query Application");
		setLayout(new GridLayout(5,1));
		pid=new TextField(50);
		pname=new TextField(50);
		next=new Button("Next");
		p=new Panel();
		add(new Label ("cCandidateCode"));
		add(pid);
		add(new Label("vFirstName"));
		add(pname);
		add(p);
		p.add(next);
		next.addActionListener(this);
		pack();
		setVisible(true);
	}

	public static void main(String a[])
	{
		QueryApp4 obj=new QueryApp4();
		try
		{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
		    con = DriverManager.getConnection("jdbc:odbc:mahendra2","sa","");
		    stat = con.createStatement();
			result = stat.executeQuery("Select ccandidatecode,vfirstname from externalcandidate");
			result.next();
		}
		catch(Exception e)
		{
			System.out.println("Error  "+e);
		}
		obj.showRecord(result);
	}

	public void actionPerformed(ActionEvent event)
	{
		if(event.getSource()==next)
		{
			try
			{
				result.next();
			}
			catch(Exception e)
			{
			}
			showRecord(result);
		}
	}

	public void showRecord(ResultSet result)
	{
		try
		{
			pid.setText(result.getString(1));
			pname.setText(result.getString(2));
		}
		catch(Exception e)
		{
		}
	}
}

