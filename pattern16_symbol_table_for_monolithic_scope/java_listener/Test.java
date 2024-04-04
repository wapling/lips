import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;

public class Test
{

  public static void main(String[] args)
  {
    try
    {
      InputStream is = (args.length > 0) ? new FileInputStream(args[0]) : System.in;
      ANTLRInputStream input = new ANTLRInputStream(is);
      CymbolLexer lexer = new CymbolLexer(input);
      CommonTokenStream tokens = new CommonTokenStream(lexer);
      CymbolParser parser = new CymbolParser(tokens);
      SymbolTable symtab = new SymbolTable();
      ParseTree tree = parser.compilationUnit();
      ParseTreeWalker walker = new ParseTreeWalker();
      TestListener listener = new TestListener(symtab);
      walker.walk(listener, tree);
      System.out.println(symtab.toString());
    }
    catch (IOException ex)
    {
      System.err.println("An error occurred: " + ex);
    }    
  }

}

