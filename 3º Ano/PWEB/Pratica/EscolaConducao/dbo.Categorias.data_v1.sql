SET IDENTITY_INSERT [dbo].[Categorias] ON
DELETE FROM Categorias
INSERT INTO [dbo].[Categorias] ([Id], [Nome], [Descricao], [Disponivel]) VALUES (1, N'AM', N'AM', 1)
INSERT INTO [dbo].[Categorias] ([Id], [Nome], [Descricao], [Disponivel]) VALUES (2, N'A1', N'A1', 1)
INSERT INTO [dbo].[Categorias] ([Id], [Nome], [Descricao], [Disponivel]) VALUES (3, N'A2', N'A2', 1)
INSERT INTO [dbo].[Categorias] ([Id], [Nome], [Descricao], [Disponivel]) VALUES (4, N'A', N'A', 1)
INSERT INTO [dbo].[Categorias] ([Id], [Nome], [Descricao], [Disponivel]) VALUES (5, N'B1', N'B1', 1)
INSERT INTO [dbo].[Categorias] ([Id], [Nome], [Descricao], [Disponivel]) VALUES (6, N'A1B1', N'A1B1', 1)
INSERT INTO [dbo].[Categorias] ([Id], [Nome], [Descricao], [Disponivel]) VALUES (7, N'A2B', N'A2B', 1)
INSERT INTO [dbo].[Categorias] ([Id], [Nome], [Descricao], [Disponivel]) VALUES (8, N'AB', N'AB', 1)
INSERT INTO [dbo].[Categorias] ([Id], [Nome], [Descricao], [Disponivel]) VALUES (9, N'B', N'B', 1)
INSERT INTO [dbo].[Categorias] ([Id], [Nome], [Descricao], [Disponivel]) VALUES (10, N'A1B', N'A1B', 1)
SET IDENTITY_INSERT [dbo].[Categorias] OFF
