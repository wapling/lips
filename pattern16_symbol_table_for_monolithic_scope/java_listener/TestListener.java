

class TestListener extends CymbolBaseListener
{
  SymbolTable symtab;

  public TestListener(SymbolTable symtab)
  {
    this.symtab = symtab;
  }

	@Override
  public void enterVarDeclaration(CymbolParser.VarDeclarationContext ctx)
  {
    System.out.println("line " + ctx.ID().getSymbol().getLine() + ": def " + ctx.ID().getText());
    VariableSymbol vs = 
      new VariableSymbol(ctx.ID().getText(), (Type)symtab.resolve(ctx.type().getText()));
    symtab.define(vs);
  }

	@Override
	public void exitType(CymbolParser.TypeContext ctx)
  {
    Type tsym = (Type)symtab.resolve(ctx.getText());
    System.out.println("line " + ctx.start.getLine() + ": ref " + tsym.getName());
  }


	@Override
  public void enterPrimary_id(CymbolParser.Primary_idContext ctx)
  {
    System.out.println("line " + ctx.ID().getSymbol().getLine() +
                       ": ref to " + symtab.resolve(ctx.ID().getText()));
  }
}

