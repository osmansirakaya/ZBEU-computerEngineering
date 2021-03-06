USE [master]
GO
/****** Object:  Database [intTek2oKullanici]    Script Date: 29.03.2021 22:06:45 ******/
CREATE DATABASE [intTek2oKullanici]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'intTek2oKullanici', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.MSSQLSERVER\MSSQL\DATA\intTek2oKullanici.mdf' , SIZE = 5120KB , MAXSIZE = UNLIMITED, FILEGROWTH = 1024KB )
 LOG ON 
( NAME = N'intTek2oKullanici_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.MSSQLSERVER\MSSQL\DATA\intTek2oKullanici_log.ldf' , SIZE = 2048KB , MAXSIZE = 2048GB , FILEGROWTH = 10%)
GO
ALTER DATABASE [intTek2oKullanici] SET COMPATIBILITY_LEVEL = 120
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [intTek2oKullanici].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [intTek2oKullanici] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET ARITHABORT OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [intTek2oKullanici] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [intTek2oKullanici] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET  DISABLE_BROKER 
GO
ALTER DATABASE [intTek2oKullanici] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [intTek2oKullanici] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET RECOVERY FULL 
GO
ALTER DATABASE [intTek2oKullanici] SET  MULTI_USER 
GO
ALTER DATABASE [intTek2oKullanici] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [intTek2oKullanici] SET DB_CHAINING OFF 
GO
ALTER DATABASE [intTek2oKullanici] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [intTek2oKullanici] SET TARGET_RECOVERY_TIME = 0 SECONDS 
GO
ALTER DATABASE [intTek2oKullanici] SET DELAYED_DURABILITY = DISABLED 
GO
EXEC sys.sp_db_vardecimal_storage_format N'intTek2oKullanici', N'ON'
GO
USE [intTek2oKullanici]
GO
/****** Object:  Table [dbo].[Kullanici]    Script Date: 29.03.2021 22:06:45 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Kullanici](
	[KullaniciID] [int] IDENTITY(1,1) NOT NULL,
	[AdSoyad] [nvarchar](50) NOT NULL,
	[MailAdresi] [nvarchar](50) NOT NULL,
	[Sifre] [nvarchar](50) NOT NULL,
	[TC] [nvarchar](11) NULL,
	[Adres] [nvarchar](200) NULL,
	[Tel] [nvarchar](11) NULL,
	[DogumTarihi] [datetime] NULL,
	[KayitTarihi] [datetime] NULL CONSTRAINT [DF_Kullanici_KayitTarihi]  DEFAULT (getdate()),
 CONSTRAINT [PK_Kullanici] PRIMARY KEY CLUSTERED 
(
	[KullaniciID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET IDENTITY_INSERT [dbo].[Kullanici] ON 

GO
INSERT [dbo].[Kullanici] ([KullaniciID], [AdSoyad], [MailAdresi], [Sifre], [TC], [Adres], [Tel], [DogumTarihi], [KayitTarihi]) VALUES (1, N'Serkan TELCİ', N'serkan@s.com', N'123', N'123', NULL, NULL, NULL, CAST(N'2021-03-29 20:35:30.007' AS DateTime))
GO
INSERT [dbo].[Kullanici] ([KullaniciID], [AdSoyad], [MailAdresi], [Sifre], [TC], [Adres], [Tel], [DogumTarihi], [KayitTarihi]) VALUES (2, N'Ali Veli', N'ali@a.com', N'1234', N'1234', NULL, NULL, NULL, CAST(N'2021-03-29 20:35:59.577' AS DateTime))
GO
INSERT [dbo].[Kullanici] ([KullaniciID], [AdSoyad], [MailAdresi], [Sifre], [TC], [Adres], [Tel], [DogumTarihi], [KayitTarihi]) VALUES (3, N'Veli Ali', N'veli@v.com', N'456', NULL, NULL, NULL, NULL, CAST(N'2021-03-29 20:36:08.717' AS DateTime))
GO
INSERT [dbo].[Kullanici] ([KullaniciID], [AdSoyad], [MailAdresi], [Sifre], [TC], [Adres], [Tel], [DogumTarihi], [KayitTarihi]) VALUES (4, N'Ayşe Can', N'ayse@a.com', N'654', NULL, N'1364', N'345234', NULL, CAST(N'2021-03-29 20:36:22.127' AS DateTime))
GO
INSERT [dbo].[Kullanici] ([KullaniciID], [AdSoyad], [MailAdresi], [Sifre], [TC], [Adres], [Tel], [DogumTarihi], [KayitTarihi]) VALUES (5, N'Fatma Bilge', N'fatma@f.com', N'9876', N'987', N'987', N'987', CAST(N'2000-01-12 00:00:00.000' AS DateTime), CAST(N'2021-03-29 20:36:33.897' AS DateTime))
GO
SET IDENTITY_INSERT [dbo].[Kullanici] OFF
GO
USE [master]
GO
ALTER DATABASE [intTek2oKullanici] SET  READ_WRITE 
GO
