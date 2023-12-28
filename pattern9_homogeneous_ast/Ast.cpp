#include "Ast.h"

#include <sstream>

  void Ast::to_string_tree(std::ostream& ostrm) const
  {
    if (children_.empty())
    {
      ostrm << to_string();
      return;
    }

    if (!is_nil())
      ostrm << '(' << to_string() << ' ';

    bool first = true;
    for (auto const& ast : children_)
    {
      if (first)
        first = false;
      else
        ostrm << ' ';
      ast.to_string_tree(ostrm);
    }
    if (!is_nil())
      ostrm << ')';
  }

  std::string Ast::to_string_tree() const
  {
    if (children_.empty())
      return to_string();

    std::ostringstream oss;
    to_string_tree(oss);
    return oss.str();
  }
