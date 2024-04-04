

class TestListener extends PrinterBaseListener
{
  boolean in_vec = false;
  boolean first_val = false;
  char    infix_op = '\0';

	@Override
  public void enterStat_equals(PrinterParser.Stat_equalsContext ctx)
  {
    System.out.print(ctx.ID().getText() + " = ");
  }

	@Override
  public void exitStat_equals(PrinterParser.Stat_equalsContext ctx)
  {
    System.out.print("\n");
  }

	@Override
  public void enterStat_print(PrinterParser.Stat_printContext ctx)
  {
    System.out.print("print ");
  }

	@Override
  public void exitStat_print(PrinterParser.Stat_printContext ctx)
  {
    System.out.print("\n");
  }

	@Override
  public void enterExpr(PrinterParser.ExprContext ctx)
  {
    if (ctx.multExpr().size() > 1)
      infix_op = '+';
    //  System.out.print("+");
  }

	@Override
  public void enterMultExpr(PrinterParser.MultExprContext ctx)
  {
    if (ctx.primary().size() > 1)
      infix_op = '*';
    //  System.out.print("*");
  }

	@Override
  public void enterPrimary_int(PrinterParser.Primary_intContext ctx)
  {
    print_comma();
    System.out.print(ctx.INT().getText());
    print_infix_op();
  }

	@Override
  public void enterPrimary_id(PrinterParser.Primary_idContext ctx)
  {
    print_comma();
    System.out.print(ctx.ID().getText());
    print_infix_op();
  }

	@Override
  public void enterPrimary_vec(PrinterParser.Primary_vecContext ctx)
  {
    in_vec = true;
    first_val = true;
    System.out.print("[");
  }

	@Override
  public void exitPrimary_vec(PrinterParser.Primary_vecContext ctx)
  {
    in_vec = false;
    System.out.print("]");
  }

  protected void print_infix_op()
  {
    if (infix_op != '\0')
    {
      System.out.print(infix_op);
      infix_op = '\0';
    }
  }

  protected void print_comma()
  {
    if (in_vec)
    {
      if (first_val)
        first_val = false;
      else
        System.out.print(", ");
    }
  }
}

