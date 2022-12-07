using System;
using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace EscolaConducao.Data.Migrations
{
    public partial class Migracao5Agendamentos : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Cursos_Categorias_CategoriaId",
                table: "Cursos");

            migrationBuilder.AlterColumn<int>(
                name: "CategoriaId",
                table: "Cursos",
                type: "int",
                nullable: true,
                oldClrType: typeof(int),
                oldType: "int");

            migrationBuilder.CreateTable(
                name: "TiposDeAula",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Nome = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    ValorHora = table.Column<decimal>(type: "decimal(18,2)", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_TiposDeAula", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "Agendamentos",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Cliente = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    DataInicio = table.Column<DateTime>(type: "datetime2", nullable: false),
                    DataFim = table.Column<DateTime>(type: "datetime2", nullable: false),
                    DuracaoEmHoras = table.Column<int>(type: "int", nullable: false),
                    DuracaoEmMinutos = table.Column<int>(type: "int", nullable: false),
                    Preco = table.Column<decimal>(type: "decimal(18,2)", nullable: false),
                    DataHoraDoPedido = table.Column<DateTime>(type: "datetime2", nullable: false),
                    TipoDeAulaId = table.Column<int>(type: "int", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Agendamentos", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Agendamentos_TiposDeAula_TipoDeAulaId",
                        column: x => x.TipoDeAulaId,
                        principalTable: "TiposDeAula",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateIndex(
                name: "IX_Agendamentos_TipoDeAulaId",
                table: "Agendamentos",
                column: "TipoDeAulaId");

            migrationBuilder.AddForeignKey(
                name: "FK_Cursos_Categorias_CategoriaId",
                table: "Cursos",
                column: "CategoriaId",
                principalTable: "Categorias",
                principalColumn: "Id");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Cursos_Categorias_CategoriaId",
                table: "Cursos");

            migrationBuilder.DropTable(
                name: "Agendamentos");

            migrationBuilder.DropTable(
                name: "TiposDeAula");

            migrationBuilder.AlterColumn<int>(
                name: "CategoriaId",
                table: "Cursos",
                type: "int",
                nullable: false,
                defaultValue: 0,
                oldClrType: typeof(int),
                oldType: "int",
                oldNullable: true);

            migrationBuilder.AddForeignKey(
                name: "FK_Cursos_Categorias_CategoriaId",
                table: "Cursos",
                column: "CategoriaId",
                principalTable: "Categorias",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }
    }
}
