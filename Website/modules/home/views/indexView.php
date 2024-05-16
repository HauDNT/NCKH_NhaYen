<!-- Header -->
<?php require "./layout/header.php" ?>

<!-- Navbar -->
<nav>
    <div class="logo">
        <i class="bx bx-menu menu-icon"></i>
        <span class="logo-name">Logo</span>
    </div>

    <!-- Sidebar -->
    <div class="sidebar">
        <div class="logo">
            <i class="bx bx-menu menu-icon"></i>
            <span class="logo-name">Quản lý nhà yến</span>
        </div>

        <div class="sidebar-content">
            <ul class="lists">
                <li class="list">
                    <a href="#" class="nav-link">
                        <i class="bx bxs-home icon"></i>
                        <span class="link">Dashboard</span>
                    </a>
                </li>
                <li class="list">
                    <a href="#" class="nav-link">
                        <i class="bx bxs-bar-chart-alt-2 icon"></i>
                        <span class="link">Báo cáo</span>
                    </a>
                </li>
                <li class="list">
                    <a href="#" class="nav-link">
                        <i class="bx bxs-certification icon"></i>
                        <span class="link">Nhiệt độ, độ ẩm</span>
                    </a>
                </li>
                <li class="list">
                    <a href="#" class="nav-link">
                        <i class="bx bxs-hot icon"></i>
                        <span class="link">Báo cháy</span>
                    </a>
                </li>
                <li class="list">
                    <a href="#" class="nav-link">
                        <i class="bx bxs-cog icon"></i>
                        <span class="link">Thiết lập</span>
                    </a>
                </li>
            </ul>

            <div class="bottom-cotent">
                <li class="list">
                    <a href="#" class="nav-link">
                        <i class="bx bx-log-out icon"></i>
                        <span class="link">Đăng xuất</span>
                    </a>
                </li>
            </div>
        </div>
    </div>
</nav>

<div class="container-fluid mainpage">
    <div class="row">
        <div class="col-sm-12">
            <div class="row">
                <h3>Thống kê</h3>
            </div>
            <!-- Dropdowns -->
            <!-- <div class="row dropdown-wrapper">
                <div class="dropdown">
                    <button class="btn dropdown-toggle" type="button" id="dropdownMenuButton" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                        Vị trí
                    </button>
                    <div class="dropdown-menu" aria-labelledby="dropdownMenuButton">
                        <a class="dropdown-item" href="#">Action</a>
                    </div>
                </div>
                <div class="dropdown">
                    <button class="btn dropdown-toggle" type="button" id="dropdownMenuButton" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                        Nhiệt độ
                    </button>
                    <div class="dropdown-menu" aria-labelledby="dropdownMenuButton">
                        <a class="dropdown-item" href="#">Action</a>
                    </div>
                </div>
                <div class="dropdown">
                    <button class="btn dropdown-toggle" type="button" id="dropdownMenuButton" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                        Tháng
                    </button>
                    <div class="dropdown-menu" aria-labelledby="dropdownMenuButton">
                        <a class="dropdown-item" href="#">Action</a>
                    </div>
                </div>
            </div> -->

            <div class="d-flex">
                <select class="form-select w-auto me-2" style="cursor: pointer" aria-label="Default select example">
                    <option selected disabled hidden>Vị trí</option>
                    <option value="1">One</option>
                    <option value="2">Two</option>
                    <option value="3">Three</option>
                </select>
    
                <select class="form-select w-auto me-2" style="cursor: pointer" aria-label="Default select example">
                    <option value="1">Nhiệt độ</option>
                    <option value="2">Độ ẩm</option>
                </select>

                <select class="form-select w-auto" style="cursor: pointer" aria-label="Default select example">
                    <option value="1">Năm</option>
                    <option value="2" selected>Tháng</option>
                    <option value="3">Ngày</option>
                </select>
            </div>

            <!-- Cards -->
            <div class="row card-wrapper">
                <div class="card col-sm-2">
                    <div class="card-body">
                        <div class="card-heading">
                            <div class="col-2">
                                <i class="bx bxs-certification icon"></i>
                            </div>
                            <div class="col">
                                <h5 class="card-title">Nhiệt độ, độ ẩm</h5>
                                <h6 class="card-subtitle mb-2 active">Đang hoạt động</h6>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="card col-sm-2">
                    <div class="card-body">
                        <div class="card-heading">
                            <div class="col-2">
                                <i class="bx bxs-hot icon"></i>
                            </div>
                            <div class="col">
                                <h5 class="card-title">Báo cháy</h5>
                                <h6 class="card-subtitle mb-2 unactive">Không kết nối</h6>
                            </div>
                        </div>
                    </div>
                </div>
            </div>

            <!-- Chart -->
            <div class="row chart-wrapper col-sm-12">
                <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/bd/Pushkin_population_history.svg/1200px-Pushkin_population_history.svg.png" alt="">
            </div>
        </div>
    </div>
</div>

<section class="overlay"></section>

<!-- Footer -->
<?php require "./layout/footer.php" ?>