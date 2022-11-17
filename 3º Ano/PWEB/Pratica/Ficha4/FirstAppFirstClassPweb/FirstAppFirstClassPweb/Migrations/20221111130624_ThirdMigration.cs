using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace FirstAppFirstClassPweb.Migrations
{
    public partial class ThirdMigration : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<int>(
                name: "TipoDeAulaId",
                table: "Agendamentos",
                type: "int",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.CreateIndex(
                name: "IX_Agendamentos_TipoDeAulaId",
                table: "Agendamentos",
                column: "TipoDeAulaId");

            migrationBuilder.AddForeignKey(
                name: "FK_Agendamentos_TiposDeAulas_TipoDeAulaId",
                table: "Agendamentos",
                column: "TipoDeAulaId",
                principalTable: "TiposDeAulas",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Agendamentos_TiposDeAulas_TipoDeAulaId",
                table: "Agendamentos");

            migrationBuilder.DropIndex(
                name: "IX_Agendamentos_TipoDeAulaId",
                table: "Agendamentos");

            migrationBuilder.DropColumn(
                name: "TipoDeAulaId",
                table: "Agendamentos");
        }
    }
}
