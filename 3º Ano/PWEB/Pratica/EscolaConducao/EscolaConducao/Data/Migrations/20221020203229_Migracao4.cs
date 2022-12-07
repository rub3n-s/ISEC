using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace EscolaConducao.Data.Migrations
{
    public partial class Migracao4 : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "Categoria",
                table: "Cursos");

            migrationBuilder.AddColumn<int>(
                name: "CategoriaId",
                table: "Cursos",
                type: "int",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.CreateTable(
                name: "Categorias",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Nome = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Descricao = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Disponivel = table.Column<bool>(type: "bit", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Categorias", x => x.Id);
                });

            migrationBuilder.CreateIndex(
                name: "IX_Cursos_CategoriaId",
                table: "Cursos",
                column: "CategoriaId");

            migrationBuilder.AddForeignKey(
                name: "FK_Cursos_Categorias_CategoriaId",
                table: "Cursos",
                column: "CategoriaId",
                principalTable: "Categorias",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Cursos_Categorias_CategoriaId",
                table: "Cursos");

            migrationBuilder.DropTable(
                name: "Categorias");

            migrationBuilder.DropIndex(
                name: "IX_Cursos_CategoriaId",
                table: "Cursos");

            migrationBuilder.DropColumn(
                name: "CategoriaId",
                table: "Cursos");

            migrationBuilder.AddColumn<string>(
                name: "Categoria",
                table: "Cursos",
                type: "nvarchar(max)",
                nullable: false,
                defaultValue: "");
        }
    }
}
