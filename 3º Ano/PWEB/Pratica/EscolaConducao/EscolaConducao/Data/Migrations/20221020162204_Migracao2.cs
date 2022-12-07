using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace EscolaConducao.Data.Migrations
{
    public partial class Migracao2 : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<decimal>(
                name: "Preco",
                table: "Cursos",
                type: "decimal(18,2)",
                nullable: true);
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "Preco",
                table: "Cursos");
        }
    }
}
