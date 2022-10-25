using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Parte_IV.Data.Migrations
{
    public partial class ForthMigration : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AlterColumn<decimal>(
                name: "Preco",
                table: "Cursos",
                type: "decimal(18,2)",
                nullable: true,
                oldClrType: typeof(decimal),
                oldType: "decimal(18,2)");

            migrationBuilder.AddColumn<bool>(
                name: "EmDestaque",
                table: "Cursos",
                type: "bit",
                nullable: false,
                defaultValue: false);
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "EmDestaque",
                table: "Cursos");

            migrationBuilder.AlterColumn<decimal>(
                name: "Preco",
                table: "Cursos",
                type: "decimal(18,2)",
                nullable: false,
                defaultValue: 0m,
                oldClrType: typeof(decimal),
                oldType: "decimal(18,2)",
                oldNullable: true);
        }
    }
}
